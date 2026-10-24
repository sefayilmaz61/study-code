#include <iostream>
#include <string>
#include <stdexcept>


class ConfigLoader
{
public:
    void load(const std::string& filename)
    {
        // 1. Empty filename
        if (filename.empty())
        {
            throw std::invalid_argument("Filename cannot be empty.");
        }

        // 2. Check file extension
        if (filename.size() < 4 ||
            filename.substr(filename.size() - 4) != ".cfg")
        {
            throw std::invalid_argument("Only .cfg files are allowed.");
        }

        // 3. Simulate missing file
        if (filename == "missing.cfg")
        {
            throw std::runtime_error("File could not be opened.");
        }

        // 4. Simulate invalid configuration
        if (filename == "invalid.cfg")
        {
            throw InvalidConfigException();
        }

        std::cout << "Configuration loaded successfully: "
                  << filename << std::endl;
    }
};

class InvalidConfigException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Configuration file is invalid.";
    }
};

int main()
{
    ConfigLoader loader;

    std::string testFiles[] =
    {
        "",
        "test.txt",
        "missing.cfg",
        "invalid.cfg",
        "settings.cfg"
    };

    for (const auto& file : testFiles)
    {
        try
        {
            std::cout << "\nLoading: " << file << std::endl;
            loader.load(file);
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Invalid argument error: "
                      << e.what() << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Runtime error: "
                      << e.what() << std::endl;
        }
        catch (const InvalidConfigException& e)
        {
            std::cout << "Config error: "
                      << e.what() << std::endl;
        }
        catch (...)
        {
            std::cout << "Unknown error occurred."
                      << std::endl;
        }
    }

    return 0;
}