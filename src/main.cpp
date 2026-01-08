#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string command;

  while (command != "exit")
  {
    std::cout << "$ ";
    std::cin >> command;

    if (command == "exit")
    {
      return 0;
    }

    std::cout << command << ": command not found" << std::endl;
  }
}
