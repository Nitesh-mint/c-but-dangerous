#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFileLength(FILE *file) {
  int fileLength;
  if (file != NULL) {
    fseek(file, 0, SEEK_END); // seek to the end of the file
    fileLength = ftell(file); // get the current file pointer
    fseek(file, 0, SEEK_SET); // set the pointer to the begining
    return fileLength;
  }
  return 0;
};

void readFile(FILE *file, int fileSize, char *fileContent) {
  if (file == NULL) {
    printf("Failed to open the file");
    exit(1);
  }

  size_t bytesRead = fread(fileContent, 1, fileSize, file);

  if (bytesRead != fileSize) {
    printf("Warning: Did not entire file\n");
  }

  fileContent[bytesRead] = '\0';

  // for (int i = 0; i < bytesRead; i++) {
  //   printf("%d", fileContent[i]);
  //   // A-Z: 65-90, a-z: 97-122
  //   if (fileContent[i] > 96 && (unsigned char)fileContent[i] < 123) {
  //     printf("<- Char\n");
  //   } else { // others are delemiters
  //     printf("<- Delemiter\n");
  //   }
  // }

  fclose(file);
};

int isCharDelimeter(unsigned char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return 0;
  } else {
    return 1;
  }
}

void tokenizeFileData(char *fileContent) {
  // char *token;
  int wordCount = 0;
  int lineCount = 0;
  size_t length = strlen(fileContent);
  for (int i = 0; i < length; i++) {
    int isCurrentChar = isCharDelimeter(fileContent[i]);
    int isNextDelimeter = isCharDelimeter(fileContent[i + 1]);

    if (fileContent[i] == '\n') {
      lineCount++;
    }
    if ((isCurrentChar == 0 && isNextDelimeter == 1)) {
      wordCount++;
    }
    // printf("Char: %u %c %d\n", fileContent[i], fileContent[i],
    //        isCharDelimeter(fileContent[i]));
  }
  printf("Total Words: %d\n", wordCount);
  printf("Total lines: %d", lineCount);
}

int main(void) {
  FILE *file;
  int fileLength;
  char *fileContent;
  file = fopen("textAnalyzer.txt", "r");
  fileLength = getFileLength(file);
  fileContent = malloc(fileLength + 1);
  readFile(file, fileLength, fileContent);
  tokenizeFileData(fileContent);
  free(fileContent);
  return 0;
}
