#include <iostream>
#include <string>
#include <complex>

using namespace std;


class complex_digit
{
public:
	complex_digit();
	~complex_digit();

private:

};

complex_digit::complex_digit()
{
}

complex_digit::~complex_digit()
{
}

void string_to_int(string buff, string& buff_Re, string& buff_Im)
{
	if (buff.find("i") != string::npos)
	{
		for (int i = buff.size(); i != 0; i--)
		{
			if (buff[i] == '-' || buff[i] == '+')
			{
				buff_Im = buff.substr(i);
				if (i != 0)
					buff_Re = buff.substr(0, i);
			}
		}
	}
	else
		buff_Re = buff;
}

string multi(string a, string b)
{
	string buff_Im;
	string buff_Re;
	string answer;
	int Im = 0;
	int Re = 0;
	string_to_int(a, buff_Re, buff_Im);
	if (buff_Re == "")
		Im = stoi(buff_Im);
	else if (buff_Im == "")
		Re = stoi(buff_Re);
	else
	{
		Re = stoi(buff_Re);
		Im = stoi(buff_Im);
	}
	string_to_int(b, buff_Re, buff_Im);
	if (buff_Re == "")
		Im *= stoi(buff_Im);
	else if (buff_Im == "")
		Re *= stoi(buff_Re);
	else
	{
		Re *= stoi(buff_Re);
		Im *= stoi(buff_Im);
	}
	if (Im > 0)
		answer += to_string(Re) + "+" + to_string(Im) + "i";
	else
		answer += to_string(Re) + to_string(Im) + "i";
	return answer;
}

string sum(string a, string b)
{
	string buff_Im;
	string buff_Re;
	string answer;
	int Im = 0;
	int Re = 0;
	string_to_int(a, buff_Re, buff_Im);
	if (buff_Re == "")
		Im = stoi(buff_Im);
	else if (buff_Im == "")
		Re = stoi(buff_Re);
	else
	{
		Re = stoi(buff_Re);
		Im = stoi(buff_Im);
	}
	string_to_int(b, buff_Re, buff_Im);
	if (buff_Re == "")
		Im += stoi(buff_Im);
	else if (buff_Im == "")
		Re += stoi(buff_Re);
	else
	{
		Re += stoi(buff_Re);
		Im += stoi(buff_Im);
	}
	if (Im > 0)
		answer += to_string(Re) + "+" + to_string(Im) + "i";
	else
		answer += to_string(Re) + to_string(Im) + "i";
	return answer;
}

int main()
{
	string test1 = "20";
	string test2 = "1-2i";
	cout << sum(test1, test2) << endl;
	cout << multi(test1, test2) << endl;
}