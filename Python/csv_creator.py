#CSV Creator
from bs4 import BeautifulSoup as bs

def from_html_table(html_source_file, output_file):
    #This will find tables, header rows, and rows
    #then output them to a file specified
    
    #Create empty dictionarys to store information
    header = []
    rows = []
    #Open file that was passed in
    with open(html_source_file, 'r') as file:    
        soup = bs(file, 'lxml')
        tables = soup.table
        try:
            #Find header Rows
            header_rows = tables.find_all('th')
            #Find regular(data) Rows
            data_rows = tables.find_all('tr')
            
            #For any Row with "#" change the text to Rank (place numer)
            #Specific to my use case
            for text_data in header_rows:
                header.append(text_data.text.strip().replace('#', 'Rank'))
        except:
            print('Unable to find HTML Tables')

    #Iterate through the data rows
    for tr in data_rows:
        #Get the data
        td = tr.find_all('td')
        #iterate through each td
        for i in td:
            #Add each td text to the rows dictionary, and get rid of extra characters
            rows.append(i.text.strip().replace(',', '').replace(' ', '').replace('\n', ''))
    if header and rows:
        create_csv(header, rows, output_file)
    else:
        print('Cannot create CSV from nothing. Check supplied file.')     

def create_csv(header, rows, output_file):
    with open(output_file, 'w') as csv_file:
        i = 1
        for header_data in header:
            if i < len(header):
                #Print each header row to the CSV file
                csv_file.writelines(f'"{header_data}",')
                i = i +1
            elif i == len(header):
                #Print the last thing in the header file with a newline char
                csv_file.writelines(f'"{header_data}",\n')
                i = 1
            else:
                print('Something bad happened.')
        i = 1
        for rows_data in rows:
            if i < len(header):
                #Print each data line to the CSV file
                csv_file.writelines(f'"{rows_data}",')
                i = i +1
            elif i == len(header):
                #Once the data reaches the length of the header length, add a newline char
                csv_file.writelines(f'"{rows_data}",\n')
                i = 1
            else:
                print('Something bad happened.')
        print(f'Created "{output_file}".')
