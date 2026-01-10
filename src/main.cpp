#include <iostream>
#include <string>

int main()
{
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string line;

  while (true)
  {
    std::cout << "$ ";
    if (!std::getline(std::cin, line))
    {
      // EOF (Ctrl-D) or input error 처리
      return 0;
    }

    // 빈 줄이면 $ 프롬프트만 다시 출력하도록 while문의 처음으로 돌아간다
    if (line.empty())
    {
      continue;
    }

    // 먼저 첫 공백 위치를 찾는다
    size_t pos = line.find(' ');

    std::string cmd;
    std::string args;

    if (pos == std::string::npos)
    {
      cmd = line;
      args = "";
    }
    else
    {
      cmd = line.substr(0, pos);
      args = line.substr(pos + 1); // 공백 다음부터 끝까지
    }

    if (cmd == "exit" && args.empty())
    {
      return 0;
    }

    if (cmd == "echo")
    {
      std::cout << args << std::endl;
    }
    else
    {
      std::cout << cmd << ": command not found" << std::endl;
    }
  }
}
