class RSA
{
public:
    double exponent(double, double, double);
    long gcd(long, long);
    
    RSA();
    double get_public_key();  //get public key
    double get_n();
    double get_private_key();  //get secret key
private:
    // two prime fixed
    
    double p = 53;
    double q = 59;

    double n = p * q;
    double phi = (p-1)*(q-1);
    double e;
    double k = 2; // A constant value
    // Secret Key
    double d = (1 + (k*phi))/e; 

    void set_e(double);
    
    void calculate_e(double);   //public key
    void calculate_d(double, double, double);     //secret key
};