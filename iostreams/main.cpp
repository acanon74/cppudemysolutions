#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};


struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
            { "Tour Ticket Prices from Miami",
              {
                      {
                              "Colombia", {
                              { "Bogota", 8778000, 400.98 },
                              { "Cali", 2401000, 424.12 },
                              { "Medellin", 2464000, 350.98 },
                              { "Cartagena", 972000, 345.34 }
                      },
                      },
                      {
                              "Brazil", {
                              { "Rio De Janiero", 13500000, 567.45 },
                              { "Sao Paulo", 11310000, 975.45 },
                              { "Salvador", 18234000, 855.99 }
                      },
                      },
                      {
                              "Chile", {
                              { "Valdivia", 260000, 569.12 },
                              { "Santiago", 7040000, 520.00 }
                      },
                      },
                      { "Argentina", {
                              { "Buenos Aires", 3010000, 723.77 }
                      }
                      },
              }
            };

    std::cout << tours.title << std::endl;

    for(auto country : tours.countries) {

        std::cout << std::setw(0);
        std::cout << country.name << std::endl;

        for(auto city : country.cities) {

            std::cout << std::setw(20) << std::setfill('_');
            std::cout << city.name;

            std::cout << std::setfill(' ') << std::setw(12);
            std::cout << city.population;

            std::cout << std::setfill(' ') << std::setw(10);
            std::cout << city.cost << std::endl;
        }

        std::cout << std::endl;

    }

    return 0;
}