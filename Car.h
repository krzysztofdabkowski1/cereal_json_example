#include <iostream>
#include <memory>
#include <cereal/types/vector.hpp>
#include <cereal/types/polymorphic.hpp>
#include <cereal/archives/json.hpp>

class Tire
{
    private:
        int typeOfRubber;    

    public:
        
         Tire(int typeOfRubber)
         {
             Tire::typeOfRubber = typeOfRubber;
         }
         Tire()
         {
             typeOfRubber = 0;
         }

        int getRubberType()
        {
            return typeOfRubber;
        }
        template <class Archive>
        void serialize( Archive & ar )
        {
            ar(CEREAL_NVP(typeOfRubber));
        }

};

class Car
{

    public:
        std::vector<Tire> tires;
        std::string name;
        Car(std::string name)
        {
            //tires.reset(new std::shared_ptr<Tire>[4]);
            Car::name = name; 
            tires.push_back(Tire(1));
            tires.push_back(Tire(1));
            tires.push_back(Tire(2));
            tires.push_back(Tire(2));
        }
        Car() = default;

        void getSound()
        {
            std::cout<<"wrooom wroom "<<name<<std::endl;
        }

        void getTiresRubberType()
        {
            std::cout<<tires[0].getRubberType()
                     <<tires[1].getRubberType()
                     <<tires[2].getRubberType()
                     <<tires[3].getRubberType();
        }

        template <class Archive>
        void serialize( Archive & ar )
        {
            ar(CEREAL_NVP(name), CEREAL_NVP(tires));
        }
};

