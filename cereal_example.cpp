#include <fstream>
#include <iostream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include "Car.h"


int main()
{
  {
    std::shared_ptr<Car> car(new Car("Renault Scenic"));
    std::shared_ptr<Car> car2(new Car("Renault Megane"));

    std::ofstream file( "data.json" );
    cereal::JSONOutputArchive archive( file ); // depending on the archive type, data may be
                                              // output to the stream as it is serialized, or
                                              // only on destruction

    archive(CEREAL_NVP(car), CEREAL_NVP(car2));  
  }
  {

    std::shared_ptr<Car> inCar;
    std::shared_ptr<Car> inCar2;

    std::ifstream ifile( "data.json");

    cereal::JSONInputArchive iarchive( ifile ); // depending on the archive type, data may be
                                              // output to the stream as it is serialized, or
                                              // only on destruction
    iarchive(inCar, inCar2);  

    inCar->getSound();
    inCar->getTiresRubberType();
  }
  
}
