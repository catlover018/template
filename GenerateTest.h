#include "bits/stdc++.h"
#include "direct.h"
#include "dirent.h"

/* --------- MANIPULATING FOLDERS AND FILES --------- */

std::string CurrentWorkingDirectory()
    {
        char* CWD = _getcwd(0, 0);
        std::string WorkingDirectory(CWD);
        free(CWD);
        return WorkingDirectory;
    }

void CreateTestsFolder()
    {
        std::string CurrentPath = CurrentWorkingDirectory();
        std::string TestFolderPath = CurrentPath + "\\Tests";

        mkdir(&TestFolderPath[0]);
    }

void BeginTest(int TestID, std::string TASKNAME, std::ofstream &INPUTSTREAM, std::ofstream &OUTPUTSTREAM)
    {
        std::string CurrentPath = CurrentWorkingDirectory();
        std::string TestFolderPath = CurrentPath + "\\Tests";

        std::string strTestID = std::to_string(TestID);
        while (strTestID.length() < 3) { strTestID = "0" + strTestID; }

        std::string SubTestFolderPath = TestFolderPath + "\\" + strTestID;

        mkdir(&SubTestFolderPath[0]);

        std::string InputFilePath = SubTestFolderPath + "\\" + TASKNAME + ".INP";
        std::string OutputFilePath = SubTestFolderPath + "\\" + TASKNAME + ".OUT";

        INPUTSTREAM.open(InputFilePath);
        OUTPUTSTREAM.open(OutputFilePath);
    }

void EndTest(std::ofstream &INPUTSTREAM, std::ofstream &OUTPUTSTREAM)
    {
        INPUTSTREAM.close();
        OUTPUTSTREAM.close();
        std::cout << '\n';
    }
/* ************************************************** */


/* --------- RANDOM METHODS --------- */

std::mt19937_64 gen(getpid());

long long randLL(long long LIM1, long long LIM2)
    {
        std::uniform_int_distribution<> distrib(LIM1, LIM2);

        return distrib(gen);
    }

long double randLD(long double LIM1, long double LIM2, int DECIMAL)
    {
        std::uniform_real_distribution<> distrib(LIM1, LIM2);

        long double P = 1.0;
        for(int i = 1; i <= DECIMAL; i++) { P *= 10.0; }

        return round(distrib(gen) * P) / P;
    }

#define LOWER_ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define UPPER_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARACTERS "!\"#$%&'()*+,-./:;<=>?@[]\\^_`{|}~"

std::string gen_string(int len, std::string &dictionary)
    {
        std::string GeneratedString;
        GeneratedString.reserve(len);

        for (int i = 0; i < len; ++i) { GeneratedString += dictionary[randLL(0, 1e9) % (dictionary.length() - 1)]; }

        return GeneratedString;
    }

std::string gen_huge_number(int len)
    {
        std::string dictionary = DIGITS;

        std::string GeneratedNumber;
        GeneratedNumber.reserve(--len);

        for (int i = 0; i < len; ++i) { GeneratedNumber += dictionary[randLL(0, 1e9) % (dictionary.length() - 1)]; }

        GeneratedNumber = std::to_string(randLL(1, 9)) + GeneratedNumber;

        return GeneratedNumber;
    }
