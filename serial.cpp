#include <iostream>

int main()
{
    testSerialComm()
}

void testSerialComm()
{

    std::string port = "COM1";
    int device = open(port.c_str(), O_RDWR | O_NOCTTY | O_SYNC);

    std::string response;
    char buffer[64];

    do
    {
        int n = read(device, buffer, sizeof buffer);

        if (n > 0) {
            response += std::string(buffer);
            std::cout << buffer;
        }

    } while (buffer[0] != 'X'); // 'X' means end of transmission

    std::cout << "Response is: " << std::endl;
    std::cout << response << std::endl;

    close(device);

}