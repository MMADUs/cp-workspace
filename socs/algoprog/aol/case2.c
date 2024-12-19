/**
* Copyright (c) 2024-2025 Muhammad Nizwa.
* AOL Algorithm & Programming
* Class LM01
* NIM 2802401833
*
* ------
* CASE 2
* ------
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CSV_PATH "../aol/file.csv"
#define MAX_DATA_CAPACITY 4000
#define QUERY_SIZE 100
#define FILENAME_SIZE 256

// data stores each information
struct data {
    char location[50];
    char city[50];
    char price[20];
    char room[20];
    char bathroom[20];
    char carpark[20];
    char type[20];
    char furnish[20];
};

// the column type used in queries
enum columnType {
    LOCATION,
    CITY,
    PRICE,
    ROOMS,
    BATHROOM,
    CARPARK,
    TYPE,
    FURNISH,
    // for invalid column type
    INVALID_COLUMN
};

// utils to get column type from string
enum columnType getColumnType(const char* columnName) {
    if (strcmp(columnName, "Location") == 0) return LOCATION;
    if (strcmp(columnName, "City") == 0) return CITY;
    if (strcmp(columnName, "Price") == 0) return PRICE;
    if (strcmp(columnName, "Rooms") == 0) return ROOMS;
    if (strcmp(columnName, "Bathroom") == 0) return BATHROOM;
    if (strcmp(columnName, "Carpark") == 0) return CARPARK;
    if (strcmp(columnName, "Type") == 0) return TYPE;
    if (strcmp(columnName, "Furnish") == 0) return FURNISH;
    return INVALID_COLUMN;
}

// the order type used during sorting
enum orderType {
    ASCENDING,
    DESCENDING,
    // for invalid order type
    INVALID_ORDER
};

// utils to get order type from string
enum orderType getOrderType(const char* orderName) {
    if (strcmp(orderName, "asc") == 0) return ASCENDING;
    if (strcmp(orderName, "desc") == 0) return DESCENDING;
    return INVALID_ORDER;
}

// display data
int displayData() {
    // open file
    FILE *file = fopen(CSV_PATH, "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }
    // insert total row to be displayed
    int rows;
    printf("Number of rows: ");
    scanf("%i", &rows);
    // check for a valid number of data
    while (rows < 1) {
        printf("Please enter a positive integer\n");
        printf("Number of rows: ");
        scanf("%i", &rows);
    }
    // data list
    struct data d[rows];
    // print header
    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    // read data to list
    for (int i = 0; i < rows; i++) {
        if (fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", d[i].location, d[i].city, d[i].price, d[i].room, d[i].bathroom, d[i].carpark, d[i].type, d[i].furnish) != 8) {
            if (feof(file)) {
                printf("End of file reached.\n");
                break;
            }
        }
        printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", d[i].location, d[i].city, d[i].price, d[i].room, d[i].bathroom, d[i].carpark, d[i].type, d[i].furnish);
    }
    fclose(file);
    return 0;
}

// used to check if a certain filed match based on the query type
bool matchSearch(const struct data* d, const enum columnType type, const char* query) {
    switch (type) {
        case LOCATION: return strcmp(d->location, query) == 0;
        case CITY: return strcmp(d->city, query) == 0;
        case PRICE: return strcmp(d->price, query) == 0;
        case ROOMS: return strcmp(d->room, query) == 0;
        case BATHROOM: return strcmp(d->bathroom, query) == 0;
        case CARPARK: return strcmp(d->carpark, query) == 0;
        case TYPE: return strcmp(d->type, query) == 0;
        case FURNISH: return strcmp(d->furnish, query) == 0;
        default: return false;
    }
}

// select row
int selectRow() {
    // open file
    FILE *file = fopen(CSV_PATH, "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }
    // query
    char column[QUERY_SIZE];
    char query[QUERY_SIZE];
    printf("Choose column: ");
    getchar();
    scanf("%[^\n]", column);
    getchar();
    printf("What data do you want to find? ");
    scanf("%[^\n]", query);
    // prepare for search
    const enum columnType columnType = getColumnType(column);
    if (columnType == INVALID_COLUMN) {
        printf("Invalid column name.\n");
        fclose(file);
        return 1;
    }
    // holds the result
    bool found = false;
    struct data d;
    // search linearly
    while (fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", d.location, d.city, d.price, d.room, d.bathroom, d.carpark, d.type, d.furnish) == 8) {
        if (matchSearch(&d, columnType, query)) {
            // this will only print the header once
            // but print all the value
            if (!found) {
                printf("Data found. Detail of data:\n");
                printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                found = true;
            }
            printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", d.location, d.city, d.price, d.room, d.bathroom, d.carpark, d.type, d.furnish);
        }
    }
    // if data not found
    if (!found) {
        printf("Not Found\n");
    }
    return 0;
}

// compare value during sort
int compareColumn(const struct data* a, const struct data* b, const enum columnType column) {
    switch (column) {
        case LOCATION: return strcmp(a->location, b->location);
        case CITY: return strcmp(a->city, b->city);
        case PRICE: return strcmp(a->price, b->price);
        case ROOMS: return strcmp(a->room, b->room);
        case BATHROOM: return strcmp(a->bathroom, b->bathroom);
        case CARPARK: return strcmp(a->carpark, b->carpark);
        case TYPE: return strcmp(a->type, b->type);
        case FURNISH: return strcmp(a->furnish, b->furnish);
        default: return 0;
    }
}

// merge function during sorting comparison
void Merge(struct data arr[], const int left, const int mid, const int right, const enum columnType column, const enum orderType order) {
    // initialize sub-array
    const int leftSize = mid - left + 1;
    const int rightSize = right - mid;
    struct data leftArr[leftSize];
    struct data rightArr[rightSize];
    // copy to sub-array
    for(int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + i + 1];
    }
    // sort & merge data
    int idx = left;
    int leftIdx = 0;
    int rightIdx = 0;
    while (leftIdx < leftSize && rightIdx < rightSize) {
        int compareResult = compareColumn(&leftArr[leftIdx], &rightArr[rightIdx], column);
        // check for order type, if asc then ignore
        if (order == DESCENDING) {
            // asc = positive value
            // desc = negative value
            compareResult = -compareResult;
        }
        if (compareResult < 0) {
            arr[idx] = leftArr[leftIdx];
            idx++;
            leftIdx++;
        } else {
            arr[idx] = rightArr[rightIdx];
            idx++;
            rightIdx++;
        }
    }
    // copy remaining
    while(leftIdx < leftSize) {
        arr[idx] = leftArr[leftIdx];
        idx++;
        leftIdx++;
    }
    while(rightIdx < rightSize) {
        arr[idx] = rightArr[rightIdx];
        idx++;
        rightIdx++;
    }
}

// used to divide array into sub-parts recursively
void Divide(struct data arr[], const int left, const int right, const enum columnType column, const enum orderType order) {
    if (left >= right) {
        return;
    }
    const int mid = (left + right) / 2;
    Divide(arr, left, mid, column, order);
    Divide(arr, mid + 1, right, column, order);
    Merge(arr, left, mid, right, column, order);
}

// sort data
int sort() {
    // open file
    FILE *file = fopen(CSV_PATH, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    // skip header line
    // because we want to sort data, so ignore header
    char header[1024];
    fgets(header, sizeof(header), file);
    // query
    char column[20];
    char order[20];
    printf("Choose column: ");
    scanf("%s", column);
    getchar();
    printf("Sort ascending or descending? ");
    scanf("%s", order);
    // get column type
    const enum columnType columnType = getColumnType(column);
    if (columnType == INVALID_COLUMN) {
        printf("Invalid column name.\n");
        fclose(file);
        return 1;
    }
    // get order type
    const enum orderType orderType = getOrderType(order);
    if (orderType == INVALID_ORDER) {
        printf("Invalid order name.\n");
        fclose(file);
        return 1;
    }
    // list of data
    struct data d[MAX_DATA_CAPACITY];
    // read process
    int count = 0;
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", d[count].location, d[count].city, d[count].price, d[count].room, d[count].bathroom, d[count].carpark, d[count].type, d[count].furnish) != EOF) {
        count++;
    }
    // merge sort
    Divide(d, 0, count - 1, columnType, orderType);
    // print header
    printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    // print first 10 sorted data
    for (int m = 0; m < count && m < 10; m++) {
        printf("%-30s %-20s %-12s %-6s %-10s %-10s %-12s %-12s\n", d[m].location, d[m].city, d[m].price, d[m].room, d[m].bathroom, d[m].carpark, d[m].type, d[m].furnish);
    }
    fclose(file);
    return 0;
}

// export write file
int export() {
    // input file metadata
    char filename[FILENAME_SIZE];
    printf("Enter the file name: ");
    scanf("%s", filename);
    // remove newline if exist & replace with null terminator
    filename[strcspn(filename, "\n")] = '\0';
    // ensure .csv extension
    if (strlen(filename) < 4 || strcmp(filename + strlen(filename) - 4, ".csv") != 0) {
        strcat(filename, ".csv");
    }
    // open both file
    FILE *export = fopen(filename, "w");
    FILE *file = fopen(CSV_PATH, "r");
    if (export == NULL || file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    // export data from file to file
    struct data d;
    while (fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", d.location, d.city, d.price, d.room, d.bathroom, d.carpark, d.type, d.furnish) == 8) {
        fprintf(export, "%s,%s,%s,%s,%s,%s,%s,%s\n", d.location, d.city, d.price, d.room, d.bathroom, d.carpark, d.type, d.furnish);
    }
    printf("Data successfully written to file %s!\n", filename);
    fclose(export);
    fclose(file);
    return 0;
}

void by_nizwa() {
    printf("\n");
    printf("\n");
    printf("  NNN    NN   NNNN   NNNNNNN   NN      NN    NNNNN    \n");
    printf("  NNNN   NN    NN        NNN   NN      NN   NN   NN   \n");
    printf("  NN NN  NN    NN       NN     NN  NN  NN   NNNNNNN   \n");
    printf("  NN  NN NN    NN     NNN      NN  NN  NN   NN   NN   \n");
    printf("  NN   NNNN   NNNN   NNNNNNN    NN NN NN    NN   NN   \n");
    printf("\n");
    printf("\n");
}

// main entry
int main() {
    int choice;
    by_nizwa();
    do {
        // display menu
        printf("What do you want to do?\n");
        printf("1. Display Data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit\nYour choice: ");
        scanf("%d", &choice);
        // options
        switch (choice) {
            case 1:
                displayData();
            break;
            case 2:
                selectRow();
            break;
            case 3:
                sort();
            break;
            case 4:
                export();
            break;
            case 5:
                printf("Exiting Program.\n");
            break;
            default:
                printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);
    return 0;
}