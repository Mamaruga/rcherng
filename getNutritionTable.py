# 2013.12.20 23:34:43 PST
import csv
import urllib2
import re
import time
import sys

def getTable(sku):
    f = open('temp', 'w')
    end = False
    while not end:
        try:
            response = response = urllib2.urlopen('http://www.europasports.com/register/tour/details.cfm?stock_code=' + sku + '&CFID=17262813&CFTOKEN=fd4d184c65e23ad8-BC9AD325-F6F3-076D-A8FB857C4157A0C7')
            end = True
        except urllib2.URLError:
            print 'Retrying on ' + sku
            time.sleep(5)
        except:
            print 'Error on: ' + sku
            return ''

    print sku
    content = response.read()
    startPos = content.find('<div style="float:left; margin-right:5px;">')
    if startPos == -1:
        return ''
    endPos = content.rfind('<div style="float:right;')
    f.write(content[startPos:endPos])
    f.close()
    a = open('temp')
    b = a.readlines()
    s = ''
    for i in b:
        if i:
            s += i.strip()

    return s.replace('float:left', 'float:right')



def format(des):
    startPos = des.find('<h3>Warnings</h3>')
    endPos = len(des)
    empty = des[startPos:endPos].find('<p></p>')
    if empty != -1:
        des = des[:(startPos + 17)] + '<p>Keep out of the reach of children</p>'
        return des
    else:
        return des



def extractNutritionTable():
    output = open('NutritionTable/output.csv', 'w')
    for row in csv.reader(open('NutritionTable/download.csv', 'rb')):
        sku = ''.join(row[3])
        b = ''.join(row[5])
        if sku and b:
            html = getTable(sku)
            if html:
                output.write(html + format(b) + '</div>' + '\n')
            else:
                output.write(format(b) + '\n')
        else:
            output.write('\n')

    output.close()



def main():
    """First argument is DF_Product_2_0.csv, and the second is product-2013-xx-yy"""
    hashset = set()
    with open(sys.argv[1], 'r') as fin:
        with open('temp', 'w') as fout:
            writer = csv.writer(fout)
            first = False
            itemType = 'Product'
            productName = ''
            productType = 'P'
            for row in csv.reader(fin):
                if first == False:
                    first = True
                else:
                    hashset.add(row[0])
                    productName = "'" + row[12] + ', ' + row[38] + "'"
                    sku = row[0]
                    if row[11]:
                        itemType = 'SKU'
                        productType = ''
                    productDescription = getTable(sku)
                    writer.writerow([itemType,
                     "''",
                     productName,
                     productType,
                     sku,
                     row[8],
                     row[8],
                     row[11],
                     row[16],
                     row[17],
                     row[22],
                     row[34],
                     row[35],
                     row[36],
                     row[37],
                     row[40],
                     row[41],
                     row[42],
                     row[48]])




def test():
    print 'test'


if __name__ == '__main__':
    main()

+++ okay decompyling /home/lynn/scripts/python/imagemuscle/qscript/getNutritionTable.pyc 
# decompiled 1 files: 1 okay, 0 failed, 0 verify failed
# 2013.12.20 23:34:44 PST
