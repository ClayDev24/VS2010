#include <iostream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

void rename_files(const std::string& folder_path, const std::string& extension) {
    for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (!entry.is_regular_file()) {
            continue;
        }
        std::string filename = entry.path().filename();
        std::string base_name = filename.substr(0, filename.find_last_of('.'));
        std::string file_extension = filename.substr(filename.find_last_of('.'));
        if (file_extension == extension) {
            std::regex pattern(R"(\d+$)");
            std::smatch match;
            if (std::regex_search(base_name, match, pattern)) {
                std::string last_number = match[0];
                std::string new_name = "NE" + last_number + ".pdf";
                fs::rename(entry.path(), entry.path().parent_path() / new_name);
            } else {
                std::cout << "Nenhum n�mero encontrado." << std::endl;
            }
        }
    }
}

int main() {
    std::string folder_path = "./renomear/";
    std::string extension = ".pdf";
    rename_files(folder_path, extension);
    return 0;
}
