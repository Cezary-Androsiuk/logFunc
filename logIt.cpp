

// #include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <stdarg.h> // va_list...


// virtual class without objects
class logIt{
	static std::string prePath;
public:
    // logIt(char*, ...);
    // ~logIt();

	void addPrePath(const std::string&);
    void log(char*, ...);
private:
    // char* convert(unsigned int, int);
};


void logIt::addPrePath(const std::string& path){
	this->prePath = path;
}

void logIt::log(char* text, ...){
	unsigned long long filesPerSec = -1;
	std::string tmpPath;
	
	std::ofstream file;
	std::ifstream exist;
	do{
		exist.close();
		filesPerSec++;
		tmpPath = this->prePath + "_" + std::to_string(std::time(0)) + "_" + std::to_string(filesPerSec) + ".log";
		exist.open(tmpPath.c_str(), std::ios::in);
		// find first free space on Y: example.Log_XXXXXXXXXX_Y
		// files in one second above 0xFFFFFFFFFFFFFFFF will be over writed
	} while (file.good());
	exist.close();
	file.open(tmpPath.c_str(), std::ios::out); // first file, which was not found

	

    char* handleText;
    handleText = text;
	unsigned long long x;

	va_list arg; 
	va_start(arg, text); 
	

    while (*handleText != '\0'){

        if(*handleText == '%'){
        	handleText++;
			switch (*handleText){
				// https://cplusplus.com/reference/cstdio/printf/ 
				// switch details
			case '%':
				file << "%";
				break;
			case 'd': // Signed decimal integer
			case 'i': // Signed decimal integer
				file << va_arg(arg,int);
				break;
			case 'u': // Unsigned decimal integer
				file << va_arg(arg,unsigned int);
				break;
			case 'o': // Unsigned octal
				break;
			case 'x': // Unsigned hexadecimal integer
				break;
			case 'X': // Unsigned hexadecimal integer (uppercase)
				break;
			case 'f': // Decimal floating point
			case 'F': // Decimal floating point
				break;
			case 'e': // Scientific notation (mantissa/exponent), lowercase
				break;
			case 'E': // Scientific notation (mantissa/exponent), uppercase
				break;
			case 'g': // Use the shortest representation: %e or %f
				break;
			case 'G': // Use the shortest representation: %E or %F
				break;
			case 'a': // Hexadecimal floating point, lowercase
				break;
			case 'A': // Hexadecimal floating point, uppercase
				break;
			case 'c': // Character
				break;
			case 's': // String of characters
				break;
			case 'p': // Pointer address
				break;
			case 'n': // Nothing printed
				break;
			default:
				break;
			}
        }
		file << *handleText;
        handleText++;
    }

	va_end(arg); 
    file.close();
}

// logIt::logIt(){

// }

// logIt::~logIt(){

// }