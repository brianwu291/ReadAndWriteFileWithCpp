#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
// #include <dbg.h>

std::string filterNum(std::string numStr, int numToFilter) {
  int length = numStr.size();
  std::string result;
  for (int i = 0; i < length; i += 2) {
    std::stringstream strStream;
    strStream << numStr[i];
    int num;
    strStream >> num;
    if (numToFilter != num) {
      result = (
        result.size() > 0
          ? result + " " + numStr[i]
          : result + numStr[i]
      );
    }
  }
  return result;
}

int main() {
  std::vector<std::vector<int>> numsByLine;
  std::fstream fileStreamForOpen;
  fileStreamForOpen.open("file.txt", std::ios::in);

  std::string totalStr = "";
  if (!fileStreamForOpen.is_open()) {
    std::cout << "Failed to open file.\n";
  } else {
    std::string s;
    while (std::getline(fileStreamForOpen, s)) {
      std::string filteredNumtext = filterNum(s, 4);
      totalStr = (
        totalStr.size() > 0
          ? totalStr + "\n" + filteredNumtext
          : totalStr + filteredNumtext
      );
    }
    std::fstream fileStreamForWrite;
    fileStreamForWrite.open("file2.txt");
    fileStreamForWrite.write(totalStr.data(), totalStr.size());
    fileStreamForOpen.close();
  }
  fileStreamForOpen.close();
  return 0;
}
