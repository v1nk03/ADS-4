// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int arrLength, int targetSum) {
  int pairCount = 0;
  for (int i = 0; i < arrLength; i++) {
    for (int j = i + 1; j < arrLength; j++) {
      if (arr[i] + arr[j] == targetSum) {
        pairCount++;
      }
    }
  }
  return pairCount;
}

int countPairs2(int *arr, int arrLength, int targetSum) {
  int pairCount = 0;
  int endIndex = arrLength - 1;
  while (endIndex > 0 && arr[endIndex] > targetSum) {
    endIndex--;
  }
  for (int leftIndex = 0; leftIndex < arrLength; leftIndex++) {
    for (int rightIndex = endIndex; rightIndex > leftIndex; rightIndex--) {
      if (arr[leftIndex] + arr[rightIndex] == targetSum) {
        pairCount++;
      }
    }
  }
  return pairCount;
}

int countPairs3(int *arr, int arrLength, int targetSum) {
  int pairCount = 0;
  for (int i = 0; i < arrLength; i++) {
    int complement = targetSum - arr[i];
    int leftIndex = i + 1;
    int rightIndex = arrLength - 1;
    while (leftIndex <= rightIndex) {
      int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
      if (arr[middleIndex] == complement) {
        pairCount++;
        int j = middleIndex - 1;
        while (j >= leftIndex && arr[j] == complement) {
          pairCount++;
          j--;
        }
        j = middleIndex + 1;
        while (j <= rightIndex && arr[j] == complement) {
          pairCount++;
          j++;
        }
        break;
      } else if (arr[middleIndex] < complement) {
        leftIndex = middleIndex + 1;
      } else {
        rightIndex = middleIndex - 1;
      }
    }
  }
  return pairCount;
}
