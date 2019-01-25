#include <iostream>
#include <string>

int main(){
	std::string oneLine="";

	while(1){
		unsigned int length=0;

		for(int i=0;i<4;i++){
			unsigned int read_char=getchar();
			length=length|(read_char<<i*8);
		}

		std::string msg="";
		for(int i=0;i<length;i++){
			msg+=getchar();
		}

		std::string message="{\"text\":\"This is a response message\"}";
		unsigned int len=message.length();

		if(msg=="{\"text\":\"#STOP#\"}"){
			message = "{\"text\":\"EXITING...\"}";
			len = message.length();

			std::cout   << char(len>>0)
                        << char(len>>8)
                        << char(len>>16)
                        << char(len>>24);

            std::cout << message;
            break;
		}

		len=length;
		std::cout << char(len>>0)
				  << char(len>>8)
				  << char(len>>16)
				  << char(len>>24);
		std::cout << msg << std::flush;
	}
	return 0;
}