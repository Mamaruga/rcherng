import urllib
import csv
import urllib2,os
'''
Need HTMLfile.txt, copy url from europa from page "just added"
Need the latest productlist from bigcommerce
This will download all the images of the new product
and create a text file contain all of the new product sku called "NewProductsku"
'''
Ulist = set()
list = set()
productList = 'products-2013-12-25.csv'

def main():
    f = open('HTMLfile.txt','r')
    content = f.read()
    list = set()
    All = False
    while not All:
        startPos = content.find('<a href="details.cfm?stock_code=')
        endPos = content.find('" class="textnav">')
        if startPos == -1:
            All = True
        else:
            if endPos-startPos > 50:
                content[startPos+len('<a href="details.cfm?stock_code='):]
                startPos = content.find('<a href="details.cfm?stock_code=')
            list.add(content[startPos+len('<a href="details.cfm?stock_code='):endPos])
            content = content[endPos+len('" class="textnav">'):]
            
    for i in list:
        cut = i.find('"><img src="')
        i = i[:cut]
        if i:
            if i[0] == '0':
                i = i[1:]
        if i:
            Ulist.add(i)

    compare()
    for i in Ulist:
        Brand = getBrand(i)
        download(i,Brand)
    
def getBrand(sku):
    end = False
    while not end:
        try:
            response = urllib2.urlopen('https://www.europasports.com/register/tour/details.cfm?stock_code='+sku+'&VENDOR_CODE=762')
            end= True
        except urllib2.URLError:
            print "Try Again"
            time.sleep(5)
        except:
            print "Error"
            return ""
    content = response.read()
    #product Name
    startPos = content.find('Catalog Tour :: ')
    endPos = content.find('</title>')
    Name = content[startPos+len('Catalog Tour :: '):endPos]
    TempContent = content[endPos:]
    N = len(Name)
    while TempContent.find(Name) == -1:
        N -= 1
        Name = Name[:N]
    return Name.strip()
    
def download(sku,Brand):
    directory = "C:\\Users\\Leaf\\Desktop\\ProductImage\\New\\"+Brand
    if not os.path.exists(directory):
        os.makedirs(directory)
    urllib.urlretrieve(getProductURL(sku),directory+"\\"+sku+".jpg")
        #urllib.urlretrieve("http://www.gunnerkrigg.com//comics/00000001.jpg", "00000001.jpg")
def getProductURL(sku):
    end = False
    while not end:
        try:
            response = urllib2.urlopen('https://www.europasports.com/register/tour/details.cfm?stock_code='+sku+'&VENDOR_CODE=762')
            #print response
            end= True
        except urllib2.URLError:
            print "Try Again"
            time.sleep(5)
        except:
            print "Error"
            return ""
    content = response.read()
    startPos = content.find('UPC')
    Tcontent = content[startPos+len('UPC:</strong> '):]
    endPos = Tcontent.find('<br />')
    num = Tcontent[:endPos].strip()
    return "https://www.europasports.com/catalog/500/"+num+".jpg"

def compare():
    with open(productList, 'rb') as f:
        csvReader = csv.reader(f)
        fi = open('NewProductSku.txt','w')
        for i in csvReader:
            if i[4] in Ulist: # 4 is the index of element containing sku
                Ulist.remove(i[4])
                print "Remove",i[4]
        for i in Ulist:
            fi.write(i+',')
main()

