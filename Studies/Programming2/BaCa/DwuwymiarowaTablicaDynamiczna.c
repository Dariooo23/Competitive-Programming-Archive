//Karol Dziekan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DeleteRow(int*** array_2d, int* rows, int** columns, int row){
    if (*rows >= 1 && row < *rows){
        int** new_array_2d = malloc((*rows - 1) * sizeof(int*));
        int* new_columns = malloc((*rows + 1) * sizeof(int));

        int i = 0, paste_index = 0;
        for(i = 0; i < *rows; i++){
            if(i == row){
                paste_index--;
            }else{
                *(new_array_2d + paste_index) = *(*(array_2d) + i);
                *(new_columns + paste_index) = *(*(columns) + i);
            }

            paste_index++;
        }

        if (row >= 0 && row < *rows) {
            free(*(*(array_2d) + row));
        }
        free(*array_2d);
        free(*columns);

        (*rows)--;
        *array_2d = new_array_2d;
        *columns = new_columns;
    }

    return;
}



void AFR(int*** array_2d, int* rows, int** columns, int* elements, int elements_number){
    int** new_array_2d = malloc((*rows + 1) * sizeof(int*));
    *new_array_2d = malloc(elements_number * sizeof(int));
    
    int i = 0;
    for(i = 1; i <= *rows; i++){
        *(new_array_2d + i) = *(*array_2d + i - 1);
    }

    int* new_columns = malloc((*rows + 1) * sizeof(int));
    *new_columns = elements_number;

    for(i = 1; i <= *rows; i++){
        *(new_columns + i) = *(*columns + i - 1);
    }

    free(*columns);
    *columns = new_columns;

    free(*array_2d);
    *array_2d = new_array_2d;

    (*rows)++;
    for(i = 0; i < elements_number; i++){
        *(*(*array_2d + 0) + i) = *(elements + i);
    }

    return;
}



void ALR(int*** array_2d, int* rows, int** columns, int* elements, int elements_number){
    int** new_array_2d = malloc((*rows + 1) * sizeof(int*));
    *(new_array_2d + *rows) = malloc(elements_number * sizeof(int));

    int i = 0;
    for(i = 0; i < *rows; i++){
        *(new_array_2d + i) = *(*array_2d + i);
    }

    int* new_columns = malloc((*rows + 1) * sizeof(int));
    *(new_columns + *rows) = elements_number;
    
    for(i = 0; i < *rows; i++){
        *(new_columns + i) = *(*columns + i);
    }

    if (*columns != NULL) {
        free(*columns);
    }
    *columns = new_columns;

    if (*array_2d != NULL) {
        free(*array_2d);
    }
    *array_2d = new_array_2d;

    (*rows)++;

    for(i = 0; i < elements_number; i++){
        *(*(*array_2d + *rows - 1) + i) = *(elements + i);
    }

    return;
}



void IBR(int*** array_2d, int* rows, int** columns, int* elements, int elements_number, int row_number){
    if (row_number < *rows){
        int** new_array_2d = malloc((*rows + 1) * sizeof(int*));
        int* new_columns = malloc((*rows + 1) * sizeof(int));
        
        int i = 0, paste_index = 0;
        for(i = 0; i < *rows + 1; i++){
            if(i == row_number){
                *(new_array_2d + i) = malloc(elements_number * sizeof(int));
                *(new_columns + i) = elements_number;
                paste_index--;
            }else{
                *(new_array_2d + i) = *(*array_2d + paste_index);
                *(new_columns + i) = *(*columns + paste_index);
            }
        
            paste_index++;
        }
    
        free(*array_2d);
        free(*columns);
    
        (*rows)++;
        *columns = new_columns;
        *array_2d = new_array_2d;

        for (i = 0; i < elements_number; i++) {
            *(*(*array_2d + row_number) + i) = *(elements + i);
        }
    }

    return;
}



void IAR(int*** array_2d, int* rows, int** columns, int* elements, int elements_number, int row_number){
    if (row_number < *rows){
        int** new_array_2d = malloc((*rows + 1) * sizeof(int*));
        int* new_columns = malloc((*rows + 1) * sizeof(int));

        int i = 0, paste_index = 0;
        for(i = 0; i < *rows + 1; i++){
            if (i == row_number + 1) {
                *(new_array_2d + i) = malloc(elements_number * sizeof(int));
                *(new_columns + i) = elements_number;
                paste_index--;
            }else{
                *(new_array_2d + i) = *(*array_2d + paste_index);
                *(new_columns + i) = *(*columns + paste_index);
            }

            paste_index++;
        }
        free(*array_2d);
        free(*columns);

        (*rows)++;
        *columns = new_columns;
        *array_2d = new_array_2d;

        for (i = 0; i < elements_number; i++) {
            *(*(*array_2d + row_number + 1) + i) = *(elements + i);
        }
    }

    return;
}



void SWR(int*** array_2d, int* rows, int** columns, int first_row, int second_row){
    if(*rows > first_row && *rows > second_row){
        int* ptr = *(*array_2d + first_row);
        *(*array_2d + first_row) = *(*array_2d + second_row);
        *(*array_2d + second_row) = ptr;

        int swap = *(*columns + first_row);
        *(*columns + first_row) = *(*columns + second_row);
        *(*columns + second_row) = swap;
    }

    return;
}



void DFR(int*** array_2d, int* rows, int** columns){
    DeleteRow(array_2d, rows, columns, 0);
    return;
}



void DLR(int*** array_2d, int* rows, int** columns){
    DeleteRow(array_2d, rows, columns, *rows - 1);
    return;
}



void RMR(int*** array_2d, int* rows, int** columns, int row){
    DeleteRow(array_2d, rows, columns, row);
    return;
}



void AFC(int*** array_2d, int* rows, int** columns, int* elements, int elements_number){
    int additional_rows = 0;
    if (elements_number > *rows){
        additional_rows = elements_number - *rows;
        elements_number = *rows;
    }

    int i = 0, j = 0;
    for(i = 0; i < elements_number; i++){
        int* new_row = malloc((1 + *(*columns + i)) * sizeof(int));

        for (j = 0; j < *(*columns + i); j++){
            *(new_row + j + 1) = *(*(*array_2d + i) + j);
        }

        *(*columns + i) += 1;
        free(*(*array_2d + i));
        *(*array_2d + i) = new_row;
    }

    for(i = 0; i < elements_number; i++){
        *(*(*array_2d + i) + 0) = *(elements + i);
    }

    int sum = *rows + additional_rows;
    for(i = *rows; i < sum; i++){
        int* new_row = malloc(sizeof(int));
        *new_row = *(elements + i);
        ALR(array_2d, rows, columns, new_row, 1);
        free(new_row);
    }
    return;
}



void ALC(int*** array_2d, int* rows, int** columns, int* elements, int elements_number){
    int additional_rows = 0;
    if(elements_number > *rows){
        additional_rows = elements_number - *rows;
        elements_number = *rows;
    }

    int i = 0, j = 0;
    for(i = 0; i < elements_number; i++){
        int* new_row = malloc((1 + *(*columns + i)) * sizeof(int));

        for(j = 0; j < *(*columns + i); j++){
            *(new_row + j) = *(*(*array_2d + i) + j);
        }

        *(*columns + i) += 1;
        free(*(*array_2d + i));
        *(*array_2d + i) = new_row;
    }

    for(i = 0; i < elements_number; i++){
        *(*(*array_2d + i) + *(*columns + i) - 1) = *(elements + i);
    }

    int sum = *rows + additional_rows;
    for(i = *rows; i < sum; i++){
        int* new_row = malloc(sizeof(int));
        *new_row = *(elements + i);

        ALR(array_2d, rows, columns, new_row, 1);
        free(new_row);
    }

    return;
}



void IBC(int*** array_2d, int* rows, int** columns, int* elements, int elements_number, int column_number){
    int elements_number_copy = elements_number;
    
    if(elements_number > *rows){
        elements_number = *rows;
    }
    
    int i = 0, j = 0;
    for(i = 0; i < elements_number; i++){
        int* new_columns = malloc((*(*columns + i) + 1) * sizeof(int));

        int paste_index = 0;
        for(j = 0; j < *(*columns + i) + 1; j++){
            if(j == column_number){
                *(new_columns + j) = 0;
                paste_index--;
            }else{
                if (paste_index != *(*columns + i)){
                    *(new_columns + j) = *(*(*array_2d + i) + paste_index);
                }
            }

            paste_index++;
        }

        *(*columns + i) += 1;
        free(*(*array_2d + i));
        *(*array_2d + i) = new_columns;
    }

    for(i = 0; i < elements_number_copy; i++){
        if(i >= *rows){
            int* element = malloc(sizeof(int));
            *element = *(elements + i);

            ALR(array_2d, rows, columns, element, 1);

            free(element);
        }else{
            if(*(*columns + i) - 1 > column_number){
                *(*(*array_2d + i) + column_number) = *(elements + i);
            }else{
                *(*(*array_2d + i) + (*(*columns + i)) - 1) = *(elements + i);
            }
        }
    }
    
    return;
}



void IAC(int*** array_2d, int* rows, int** columns, int* elements, int elements_number, int column_number){
    int elements_number_copy = elements_number;

    if(elements_number > *rows){
        elements_number = *rows;
    }

    int i = 0, j = 0;
    for(i = 0; i < elements_number; i++){
        int* new_columns = malloc((*(*columns + i) + 1) * sizeof(int));

        int paste_index = 0;
        for(j = 0; j < *(*columns + i) + 1; j++){
            if (j == column_number + 1){
                *(new_columns + j) = 0;
                paste_index--;
            }else{
                if (paste_index != *(*columns + i)){
                    *(new_columns + j) = *(*(*array_2d + i) + paste_index);
                }
            }

            paste_index++;
        }
        *(*columns + i) += 1;
        free(*(*array_2d + i));
        *(*array_2d + i) = new_columns;
    }

    for(i = 0; i < elements_number_copy; i++){
        if(i >= *rows){
            int* element = malloc(sizeof(int));
            *element = *(elements + i);

            ALR(array_2d, rows, columns, element, 1);
            free(element);
        }else{
            if(*(*columns + i) - 1 > column_number){
                *(*(*array_2d + i ) + column_number + 1) = *(elements + i);
            }else{
                *(*(*array_2d + i ) + ((*(*columns + i)) - 1)) = *(elements + i);
            }
        }
    }

    return;
}



void SWC(int*** array_2d, int* rows, int** columns, int first_column, int second_column){
    int i = 0;
    for(i = 0; i < *rows; i++){
        if(*(*columns + i) > first_column && *(*columns + i) > second_column){
            int swap = *(*(*array_2d + i) + first_column);
            *(*(*array_2d + i) + first_column) = *(*(*array_2d + i) + second_column);
            *(*(*array_2d + i) + second_column) = swap;
        }
    }

    return;
}



void DFC(int*** array_2d, int* rows, int** columns){
    if (*rows > 0){
        int i = 0, j = 0;
        for(i = 0; i < *rows; i++){
            int* new_row = malloc((*(*columns + i) - 1) * sizeof(int));
    
            for(j = 1; j < *(*columns + i); j++){
                *(new_row + j - 1) = *(*(*array_2d + i) + j);
            }
    
            if(*(*columns + i) <= 1){
                free(new_row);
                DeleteRow(array_2d, rows, columns, i);
                i--;
            }else{
                free(*(*array_2d + i));
                *(*array_2d + i) = new_row;
                (*(*columns + i))--;
            }
        }
    }

    return;
}



void DLC(int*** array_2d, int* rows, int** columns){
    if (*rows > 0){
        int i = 0, j = 0;
        for(i = 0; i < *rows; i++){
            int* new_row = malloc((*(*columns + i) - 1) * sizeof(int));
    
            for(j = 0; j < *(*columns + i) - 1; j++){
                *(new_row + j) = *(*(*array_2d + i) + j);
            }
    
            if(*(*(columns) + i) <= 1){
                free(new_row);
                DeleteRow(array_2d, rows, columns, i);
                i--;
            }else{
                free(*(*array_2d + i));
                *(*array_2d + i) = new_row;
                (*(*columns + i))--;
            }
        }
    }

    return;
}



void RMC(int*** array_2d, int* rows, int** columns, int column_number){
    if(*rows > 0){
        int i = 0, j = 0;
        for(i = 0; i < *rows; i++){
            if(column_number >= *(*columns + i)){
                continue;
            }
            
            int* new_row = malloc((*(*columns + i) - 1) * sizeof(int));
    
            if(column_number < *(*columns + i)){
                int paste_index = 0;
                for(j = 0; j < *(*columns + i); j++){
                    if(j == column_number){
                        paste_index--;
                    }else{
                        *(new_row + paste_index) = *(*(*array_2d + i) + j);
                    }
    
                    paste_index++;
                }
    
                if(*(*(columns) + i) > 1){
                    free(*(*array_2d + i));
                    *(*array_2d + i) = new_row;
                    *(*columns + i) -= 1;
                }else{
                    free(new_row);
                    DeleteRow(array_2d, rows, columns, i);
                    i--;
                }
            }
        }
    }

    return;
}



void RMB(int*** array_2d, int* rows, int** columns, int first_row, int rows_number, int first_column, int columns_number){
    int max_row = 0;

    if(*rows < first_row + rows_number){
        max_row = *rows;
    }else{
        max_row = first_row + rows_number; 
    }
    
    int row_index = first_row;
    int i = 0, j = 0;
    for(i = first_row; row_index < max_row; i++){
        if(first_column < *(*columns + i)){
            int max_column = 0;

            if(*(*columns + i) < first_column + columns_number){
                max_column = *(*columns + i);
            }else{
                max_column = first_column + columns_number;
            }
    
            if(*(*columns + i) - (max_column - first_column) > 0){
                int* new_row = malloc((*(*columns + i) - (max_column - first_column)) * sizeof(int));

                for(j = 0; j < first_column; j++){
                    *(new_row + j) = *(*(*(array_2d) + i) + j);
                }

                int column_index = first_column;
                for(j = first_column + columns_number; j < *(*(columns) + i); j++){
                    *(new_row + column_index) = *(*(*(array_2d) + i) + j);
                    column_index++;
                }

                *(*(columns) + i) = *(*(columns) + i) - (max_column - first_column);
                free(*(*(array_2d) + i));
                *(*(array_2d) + i) = new_row;
            }else{
                RMR(array_2d, rows, columns, i);
                i--;
            }
        }
        row_index++;
    }

    return;
}



void ISB(int*** array_2d, int* rows, int** columns, int** elements, int first_row, int rows_number, int first_column, int columns_number){
    int column_index = 0;

    int i = 0, j = 0;
    for(i = first_row; i < first_row + rows_number; i++){
        if(i < *rows){
            int* row = malloc((*(*columns + i) + columns_number) * sizeof(int));
            int new_first_column = 0;

            if (first_column >= *(*columns + i)){
                new_first_column = *(*columns + i);
            }else{
                new_first_column = first_column;
            }

            int index1 = 0;
            int index2 = 0;
            for(j = 0; j < *(*(columns) + i) + columns_number; j++){
                if(j >= new_first_column && j < new_first_column + columns_number){
                    *(row + j) = *(*(elements + column_index) + index2);
                    index1--;
                    index2++;
                }else{
                    *(row + j) = *(*(*array_2d + i) + index1);
                }
                index1++;
            }

            *(*columns + i) += columns_number;
            free(*(*array_2d + i));
            *(*array_2d + i) = row;
        }else{
            ALR(array_2d, rows, columns, *(elements + column_index), columns_number);
        }

        column_index++;
    }

    return;
}



void PRT(int** array_2d, int* rows, int* columns){
    printf("%d\n", *rows);

    int i = 0, j = 0;
    for(i = 0; i < *rows; i++){
        printf("%d ", *(columns + i));

        for(j = 0; j < *(columns + i); j++){
            if (j == *(columns + i) - 1){
                printf("%d", *(*(array_2d + i) + j));
            }else{
                printf("%d ", *(*(array_2d + i) + j));
            }
        }

        printf("\n");
    }

    return;
}



void WRF(int** array_2d, int rows, int* columns){
    char* file_name = malloc(20 * sizeof(char));
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "wb");

    if (file == NULL){
        free(file_name);
        return;
    }

    fprintf(file, "%d\n", rows);

    int i = 0, j = 0;
    for(i = 0; i < rows; i++){
        unsigned short columns_number = *(columns + i);

        unsigned char st_byte_c = (columns_number >> 8);
        unsigned char nd_byte_c = columns_number;

        fprintf(file, "%c%c", st_byte_c, nd_byte_c);

        for(j = 0; j < *(columns + i); j++){
            unsigned char st_byte = (*(*(array_2d + i) + j) >> 24);
            unsigned char nd_byte = (*(*(array_2d + i) + j) >> 16);
            unsigned char rd_byte = (*(*(array_2d + i) + j) >> 8);
            unsigned char th_byte = (*(*(array_2d + i) + j));

            fprintf(file, "%c%c%c%c", st_byte, nd_byte, rd_byte, th_byte);
        }

    }

    fclose(file);
    free(file_name);
    return;
}

void RDF(int*** array_2d, int *rows, int** columns){
    char* file_name = malloc(20 * sizeof(char));
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "rb");

    if(file == NULL){
        free(file_name);
        return;
    }

    int i = 0;
    for(i = 0; i < *rows; i++){
        free(*(*array_2d + i));
    }

    *rows = 0;
    free(*columns);
    free(*array_2d);


    fscanf(file, "%d", rows);

    char imagine;
    fscanf(file, "%c", &imagine);
    
    *columns = malloc(*rows * sizeof(int));
    *array_2d = malloc(*rows * sizeof(int*));

    for(i = 0; i < *rows; i++){
        unsigned short columns_number = 0;
        unsigned char st_byte_c = 0;
        unsigned char nd_byte_c = 0;

        fscanf(file, "%c%c", &st_byte_c, &nd_byte_c);
        
        columns_number = (columns_number << 8);
        columns_number = (columns_number | (st_byte_c));

        columns_number = (columns_number << 8);
        columns_number = (columns_number | (nd_byte_c));

        *(*columns + i) = columns_number;
        *(*array_2d + i) = malloc(columns_number * sizeof(int));

        int j = 0;
        for(j = 0; j < columns_number; j++){
            unsigned char st_byte = 0;
            unsigned char nd_byte = 0;
            unsigned char rd_byte = 0;
            unsigned char th_byte = 0;
            fscanf(file, "%c%c%c%c", &st_byte, &nd_byte, &rd_byte, &th_byte);

            int integer = 0;

            integer = integer << 8;
            integer = integer | (st_byte);

            integer = integer << 8;
            integer = integer | (nd_byte);

            integer = integer << 8;
            integer = integer | (rd_byte);

            integer = integer << 8;
            integer = integer | (th_byte);

            *(*(*array_2d + i) + j) = integer;
        }
    }
    
    fclose(file);
    free(file_name);
    return;
}

int main(){
    int* rows = malloc(sizeof(int));
    int* columns = malloc(0 * sizeof(int));
    int** array_2d = malloc(0 * sizeof(int*));
    char* operation = malloc(4 * sizeof(char));

    *rows = 0;

    do{
        scanf("%s", operation);

        if(strcmp(operation, "AFR") == 0){
            int elements_number = 0;
            scanf("%d", &elements_number);

            if(elements_number == 0){
                continue;
            }
            
            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }
            
            AFR(&array_2d, rows, &columns, elements, elements_number);
            free(elements);
        }
        if(strcmp(operation, "ALR") == 0){
            int elements_number = 0;;
            scanf("%d", &elements_number);

            if(elements_number == 0){
                continue;
            }

            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            ALR(&array_2d, rows, &columns, elements, elements_number);
            free(elements);
        }
        if(strcmp(operation, "AFC") == 0){
            int elements_number = 0;
            scanf("%d", &elements_number);

            if(elements_number == 0){
                continue;
            }

            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            AFC(&array_2d, rows, &columns, elements, elements_number);
            free(elements);
        }
        if(strcmp(operation, "ALC") == 0){
            int elements_number = 0;
            scanf("%d", &elements_number);

            if(elements_number == 0){
                continue;
            }

            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            ALC(&array_2d, rows, &columns, elements, elements_number);
            free(elements);
        }
        if(strcmp(operation, "IBR") == 0){
            int row_number = 0;
            scanf("%d", &row_number);
            int elements_number = 0;    
            scanf("%d", &elements_number);

            if(elements_number == 0){
                continue;
            }

            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            IBR(&array_2d, rows, &columns, elements, elements_number, row_number);
            free(elements);
        }
        if(strcmp(operation, "IAR") == 0){
            int row_number = 0;
            scanf("%d", &row_number);
            int elements_number = 0;    
            scanf("%d", &elements_number);

            if(elements_number == 0){
                continue;
            }

            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            IAR(&array_2d, rows, &columns, elements, elements_number, row_number);
            free(elements);
        }
        if(strcmp(operation, "IBC") == 0){
            int column_number = 0;
            scanf("%d", &column_number);
            int elements_number = 0;    
            scanf("%d", &elements_number);

            int* elements = malloc(elements_number * sizeof(int));

            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            IBC(&array_2d, rows, &columns, elements, elements_number, column_number);
            free(elements);
        }
        if(strcmp(operation, "IAC") == 0){
            int column_number = 0;
            scanf("%d", &column_number);
            int elements_number = 0;    
            scanf("%d", &elements_number);
            int* elements = malloc(elements_number * sizeof(int));
            int i = 0;
            for(i = 0; i < elements_number; i++){
                scanf("%d", elements + i);
            }

            IAC(&array_2d, rows, &columns, elements, elements_number, column_number);
            free(elements);
        }
        if(strcmp(operation, "SWR") == 0){
            int first_row = 0;
            int second_row = 0;
            scanf("%d %d", &first_row, &second_row);
            SWR(&array_2d, rows, &columns, first_row, second_row);
        }
        if(strcmp(operation, "SWC") == 0){
            int first_column = 0;
            int second_column = 0;
            scanf("%d %d", &first_column, &second_column);
            SWC(&array_2d, rows, &columns, first_column, second_column);
        }
        if(strcmp(operation, "DFR") == 0){
            DFR(&array_2d, rows, &columns);
        }
        if(strcmp(operation, "DLR") == 0){
            DLR(&array_2d, rows, &columns);
        }
        if(strcmp(operation, "DFC") == 0){
            DFC(&array_2d, rows, &columns);
        }
        if(strcmp(operation, "DLC") == 0){
            DLC(&array_2d, rows, &columns);
        }
        if(strcmp(operation, "RMR") == 0){
            int row_number = 0;
            scanf("%d", &row_number);
            RMR(&array_2d, rows, &columns, row_number);
        }
        if(strcmp(operation, "RMC") == 0){
            int column_number = 0;
            scanf("%d", &column_number);
            RMC(&array_2d, rows, &columns, column_number);
        }
        if(strcmp(operation, "RMB") == 0){
            int first_row = 0;
            int row_number = 0;
            int first_column = 0;
            int columns_number = 0;
            scanf("%d %d %d %d", &first_row, &row_number, &first_column, &columns_number);
            RMB(&array_2d, rows, &columns, first_row, row_number, first_column, columns_number);
        }
        if(strcmp(operation, "ISB") == 0){
            int first_row = 0;
            int first_column = 0;
            int rows_number = 0;
            int columns_number = 0;
            scanf("%d %d %d %d", &first_row, &first_column, &rows_number, &columns_number);

            int** elements = malloc(rows_number * sizeof(int*));
            int i = 0;
            for(i = 0; i < rows_number; i++){
                *(elements + i) = malloc(columns_number * sizeof(int));

                int j = 0;
                for(j = 0; j < columns_number; j++){
                    scanf("%d", (*(elements + i) + j));
                }
            }

            ISB(&array_2d, rows, &columns, elements, first_row, rows_number, first_column, columns_number);
            for(i = 0; i < rows_number; i++){
                free(*(elements + i));
            }
            free(elements);
        }
        if(strcmp(operation, "WRF") == 0){
            WRF(array_2d, *rows, columns);
        }
        if(strcmp(operation, "RDF") == 0){
            RDF(&array_2d, rows, &columns);
        }
        if(strcmp(operation, "PRT") == 0){
            PRT(array_2d, rows, columns);
        }
    }while (strcmp(operation, "END") != 0);

    int i = 0;
    for(i = 0; i < *rows; i++){
        free(*(array_2d + i));
    }

    free(rows);
    free(columns);
    free(array_2d);
    free(operation);

    return 0;
}