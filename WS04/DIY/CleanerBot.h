/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 06.13.2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define SDDS_CLEANERBOT_H
#ifndef SDDS_ClEANERBOT_H
namespace sdds
{
    class CleanerBot
    {
        char* c_location; 
        double c_battery; 
        int c_brush; 
        bool c_isActive;
        void setEmpty();
    public:
        CleanerBot(); 
        CleanerBot(const char* location, double battery, int brush, bool active);
        ~CleanerBot();
        // Modifiers
        void set(const char* location, double battery, int brush, bool active);
        void setLocation(const char* location);
        void setActive(bool active);
        // Queries
        const char* getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        void display() const;
    };
    // Helper
    int report(CleanerBot* bot, short num_bots);
    void sort(CleanerBot* bot, short num_bots);
}
#endif // !SDDS_ClEANERBOT_H
