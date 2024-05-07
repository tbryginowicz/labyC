#include <iostream>
#include <fstream>
#include <string>

int main() {
    int red = 0;
    int green = 0;
    int blue = 0;
    int limitRed = 12;
    int limitGreen = 13;
    int limitBlue = 14;
    int suma = 0;
    int mocsuma = 0;

    std::ifstream infile("input2.txt");
    std::string line;
    int id = 0;
    std::string colors[] = {"red", "green", "blue"};

    while (std::getline(infile, line)) {
        id++;
        for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
            int found = 0;
            while ((found = line.find(colors[i], found)) != std::string::npos) {
                if (found >= 3 && isdigit(line[found - 3])) {
                    std::string numberStr = line.substr(found - 3, 2);
                    int number = std::stoi(numberStr);
                    switch (i) {
                        case 0:
                            if (number > red) red = number;
                            break;
                        case 1:
                            if (number > green) green = number;
                            break;
                        case 2:
                            if (number > blue) blue = number;
                            break;
                    }
                } else if (found >= 2 && isdigit(line[found - 2])) {
                    std::string numberStr = line.substr(found - 2, 1);
                    int number = std::stoi(numberStr);
                    switch (i) {
                        case 0:
                            if (number > red) red = number;
                            break;
                        case 1:
                            if (number > green) green = number;
                            break;
                        case 2:
                            if (number > blue) blue = number;
                            break;
                    }
                }
                found++;
            }
        }
        if (red <= limitRed && blue <= limitBlue && green <= limitGreen) {
            suma += id;
        }
        int moc = red * green * blue;
        mocsuma += moc;
        red = 0;
        green = 0;
        blue = 0;
    }

    printf("\nSUMA: %d\n", suma);
    printf("\nSUMA MOCY: %d\n",mocsuma);

    infile.close();
    return 0;
}
