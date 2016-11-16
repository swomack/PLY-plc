#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <boost\tokenizer.hpp>



using namespace std;
using namespace boost;

class PLYLoader
{
private:
	int num_vertices;
public:
	void read_file(const string& file_name)
	{
		std::ifstream in(file_name);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();

			char_separator<char> sep("\n");
			tokenizer<char_separator<char>> tokens(contents, sep);

			char_separator<char> line_sep(" ");

			// parse header
			for (const auto& t : tokens) {
				//transform(t.begin(), t.end(), t.begin(), ::tolower);

				if (t == "end_header")
					break;

				tokenizer<char_separator<char>> line_tokens(t, line_sep);
			}
		}
	}
};


int main()
{
	PLYLoader loader;
	loader.read_file("pond_ascii.ply");
}