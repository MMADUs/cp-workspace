#include <stdio.h>
#include <string.h>

int displayData();
int findRow();
int menu();
int export();
int sort();

typedef struct data{
    char loc[50];
    char city[50];
    char price[20];
    char room[20];
    char bathroom[20];
    char carpark[20];
    char type[20];
    char furnish[20];
}d;



int task(int n)
{
    char col[20];
    char sorta[20];
    char filename[500];
    switch (n)
    {
    case 1:
        displayData();
        break;
    case 2:
        findRow();
        break;
    case 3:   
        scanf("%s",col);getchar();
        scanf("%s",sorta);
        sort(col, sorta);
        break;
    case 4:
        printf("Enter the file name: ");
        scanf("%s",filename);
        export(filename);
        break;
    case 5:
        printf("Exiting Program.\n");
        return 0;
        break;
    default:
        menu();
        break;
    }
    return 0;
}

int menu()
{
    int n;
    do{
    printf("What do you want to do?\n");
    printf("1. Display Data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit\nYour choice: ");
    scanf("%i", &n);
    } while (n<1||n>5);
    return n;
}

int displayData()
{
    FILE *file = fopen("file(in).csv", "r");
    if (!file)
    {
        printf("File not opened.\n");
        return 0;
    }
    int rows;
    printf("Number of rows: ");
    scanf("%i", &rows);
    
    while (rows<1)
    {
        printf("Please enter a positive integer\n");
        printf("Number of rows: ");
        scanf("%i", &rows);
    }
    d dt[rows]; 
    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n","Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i=0;i<rows;i++)
    {
        if(fscanf(file," %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dt[i].loc, dt[i].city, dt[i].price, dt[i].room, dt[i].bathroom, dt[i].carpark, dt[i].type, dt[i].furnish) != 8)
        {
            if (i>=3939)
            {
                printf("No more data to be printed\n");
            }
            else
            printf("No data found in the file.\n");
            break;
        }
        printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt[i].loc, dt[i].city, dt[i].price, dt[i].room, dt[i].bathroom, dt[i].carpark, dt[i].type, dt[i].furnish);
    }
    fclose(file);
    return 1;
}

int findRow()
{
    FILE *file = fopen("file(in).csv", "r");
    if (!file) {
        printf("File not opened.\n");
        return 0;
    }

    char col[100];
    char str[100];

    d dt;
    int check=0;

    printf("Choose column: ");getchar();
    scanf("%[^\n]", col);getchar();
    printf("What data do you want to find? ");
    scanf("%[^\n]", str); 
    while(fscanf(file," %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish) == 8)
        {
            if (strcmp(col, "Location") == 0 && strcmp(dt.loc, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n",dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            } 
    
            else if (strcmp(col, "City") == 0 && strcmp(dt.city, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            } 
            

            else if (strcmp(col, "Price") == 0 && strcmp(dt.price, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            }
            

            else if (strcmp(col, "Rooms") == 0 && strcmp(dt.room, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", 
                        "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1; 
            }
            

            else if (strcmp(col, "Bathroom") == 0 && strcmp(dt.bathroom, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            }
            

            else if (strcmp(col, "Carpark") == 0 && strcmp(dt.carpark, str) == 0)
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            }
            

            else if (strcmp(col, "Type") == 0 && strcmp(dt.type, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            }
            

            else if (strcmp(col, "Furnish") == 0 && strcmp(dt.furnish, str) == 0) 
            {
                if (check == 0) 
                {
                    printf("Data found. Detail of data:\n");
                    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                }
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
                check=1;
            }
                }
            if (check==0)
            {
                printf("Not Found\n");
            }
            return 0;
}

// int sort()
// {
//     char col[20];
//     char by[20];
//     printf("Choose Columns: ");
//     scanf("%s",col);getchar();
//     printf("Sort ascending or descending? ");
//     scanf("%s",by);
// }

int sort(char col[], char sorta[]) {
	FILE *file = fopen("file(in).csv", "r");
    if (file == NULL) {
        printf("Error: Can't open file.\n");
        return 0;
    }

    char header[1024];
    fgets(header, sizeof(header), file); 
    
    d dt[3940];
    int count = 0;
	    
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
            dt[count].loc, dt[count].city, dt[count].price, dt[count].room,
            dt[count].bathroom, dt[count].carpark, dt[count].type, dt[count].furnish) != EOF) {
        count++;
    }
    
    int i, j;
    
	for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            int compare = 0;

            if (strcmp(col, "Location") == 0) {
                compare = strcmp(dt[i].loc, dt[j].loc);
            } else if (strcmp(col, "City") == 0) {
                compare = strcmp(dt[i].city, dt[j].city);
            } else if (strcmp(col, "Type") == 0) {
                compare = strcmp(dt[i].type, dt[j].type);
            } else if (strcmp(col, "Furnish") == 0) {
                compare = strcmp(dt[i].furnish, dt[j].furnish);
            } else if (strcmp(col, "Bathroom") == 0) {
                compare = strcmp(dt[i].bathroom, dt[j].bathroom);
            }

            if ((strcmp(sorta, "asc") == 0 && compare > 0) || 
                (strcmp(sorta, "dsc") == 0 && compare < 0)) {
                d temp = dt[i];
                dt[i] = dt[j];
                dt[j] = temp;
            }
        }
    }
    
    printf("%-20s %-20s %-10s %-6s %-10s %-8s %-10s %-10s\n",
           "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
	
	int m;
    for (m = 0; m < count && m < 10; m++) {
        printf("%-20s %-20s %-10s %-6s %-10s %-8s %-10s %-10s\n",
               dt[m].loc, dt[m].city, dt[m].price, dt[m].room,
               dt[m].bathroom, dt[m].carpark, dt[m].type, dt[m].furnish);
    }
    
    fclose(file);
	return 3;
}

int export(char filename[])
{
    int end = strlen(filename)-1;
    int check=1;
    char csvcheck[4];
    
    for (int i=0;i<=3;i++)
    {
        csvcheck[i]=filename[end-3+i];
    }
    csvcheck[4]='\0';
    
    if (end<3||strcmp(csvcheck, ".csv") != 0) 
    {
        strcat(filename, ".csv");
    }
    FILE *export = fopen(filename,"w");
    FILE *file = fopen("file(in).csv", "r");
    if (!export||!file)
    {
        printf("File not opened\n");
        return 0;
    }
    d dt;
    while(fscanf(file," %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish) == 8)
    {
        fprintf(export,"%s,%s,%s,%s,%s,%s,%s,%s\n", dt.loc, dt.city, dt.price, dt.room, dt.bathroom, dt.carpark, dt.type, dt.furnish);
    }
    printf("Data successfully written to file %s!\n",filename);
}

int main(){

    int n=0;
    while (n!=5)
    {
    n = menu();
    task(n);
    }

}