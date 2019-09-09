#include "tinyicc.h"

#include <stdio.h>

std::vector<uint8_t> readFile(const char *fn)
{
    FILE *fp;
    int   r = fopen_s(&fp, fn, "rb+");
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    std::vector<uint8_t> ret(size);
    fread(ret.data(), 1, size, fp);
    fclose(fp);
    return ret;
}

int main(int argc, char *argv[])
{
    std::vector<uint8_t> file = readFile(argv[1]);
    TinyICC::Profile     profile;

    bool ret = TinyICC::loadFromMem(profile, file.data(), file.size());
    profile.dump();
}