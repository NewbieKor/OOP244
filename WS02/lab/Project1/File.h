#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* cstr);
   bool read(int& stdNumber);
   bool read(char& stdGrade);

  
}
#endif // !SDDS_FILE_H_
