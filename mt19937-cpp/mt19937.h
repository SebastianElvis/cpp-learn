#define MT_LEN 624

class MT19937{
public:
    MT19937(int seed);
    int next();
    void twist();
private:
    int MT[624];
    int index = 0;
};