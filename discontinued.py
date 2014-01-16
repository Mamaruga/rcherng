import csv

#Check for discontinued products

def main():

    list = set()
    with open('DiscontinuedProducts.csv', 'rb') as f:
        csvReader = csv.reader(f)
        for i in csvReader:
            list.add(i[1])
        #for i in list:
           #print i
        f.close()
        
    with open('products-2013-12-18.csv', 'rb') as f:
        csvReaderP = csv.reader(f)
        Dlist = set()  #list of discontinued that show up in the store
        for line in csvReaderP:
            if line[4] in list:
                if line[22] == 'Y':
                    Dlist.add(line[4])
        for i in Dlist:
            print i
                    
                
        f.close()
main()

