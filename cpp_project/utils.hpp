#using <deps/Handler.dll>
#using <deps/Newtonsoft.Json.dll>
#using <deps/TrinitySeal.dll>

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <msclr/marshal.h>
#include <WinUser.h>
#include <fstream>
#include <iomanip>

class utils {
public:
	static void check_dlls();

    static std::string wstring_to_string(const std::wstring& ws);

	static std::wstring string_to_wstring(const std::string& s);

	static bool is_dll_valid;
};
