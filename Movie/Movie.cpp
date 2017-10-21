#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

class Movie {

public:
    enum { REGULAR = 0,  NEW_RELEASE = 1,  CHILDRENS = 2 };
    Movie( string title, int priceCode ) {
        _title = title;
        _priceCode = priceCode;
    }

    int getPriceCode() {
        return _priceCode;
    }

    void setPriceCode( int arg ) {
        _priceCode = arg;
    }

    string getTitle() {
        return _title;
    }

private:                                                          
    string _title;
    int _priceCode;
};

class Rental {

public:
    Rental( Movie *movie, int daysRented ) {
        _movie = movie;
        _daysRented = daysRented;
    }

    int getDaysRented() {
        return _daysRented;
    }

    Movie *getMovie() {
        return _movie;
    }

private:
    Movie *_movie;
    int _daysRented;
};

class Customer {

public:
     Customer( string name ) {
        _name = name;
    }

    void addRental( Rental *arg ) {
        _rentals.push_back( arg );
    }

    string getName() {
        return _name;
    }

    string statement() {
        char buf[10];
        double totalAmount = 0;
        int frequentRenterPoints = 0;
        string result = "Rental Record for " + getName() +"\n";

        for( vector<Rental *>::iterator iter = _rentals.begin(); iter != _rentals.end(); ++iter ) {
            // determine amount for each rental
            Rental *thisRental = *iter;
            double thisAmount = 0;
            int numDaysRented = thisRental->getDaysRented();
            switch( thisRental->getMovie()->getPriceCode() ) {
                case Movie::REGULAR:
                    thisAmount += 2;
                    if( numDaysRented > 2 )
                        thisAmount += ( numDaysRented - 1 ) * 1.5;
                    break;
                case Movie::NEW_RELEASE:
                    thisAmount += numDaysRented * 3;
                    break;
                case Movie::CHILDRENS:
                    thisAmount += 1.5;
                    if( numDaysRented > 3 ) 
                        thisAmount += ( numDaysRented - 3 ) * 1.5;
                    break;
            }
	    frequentRenterPoints++;

            // add bonus for a two day new relase rental
            if( thisRental->getMovie()->getPriceCode() == Movie::NEW_RELEASE && 
                thisRental->getDaysRented() > 1 )
                frequentRenterPoints++;

            // show figures for this rental
            sprintf( buf, "%.2f", thisAmount );
            result += "\t" + thisRental->getMovie()->getTitle() + "\t" + buf + "\n";
            totalAmount += thisAmount;
        }

        // add footer lines
        sprintf( buf, "%.2f", totalAmount) ;
        result = result + "Amount owed is " +  buf + "\n";
        sprintf( buf, "%d", frequentRenterPoints);
        result = result + "You earned " + buf + " frequent renter points";
        return result;
    }

private:
    string _name;
    vector<Rental *> _rentals;
};

int main( int argc, char *argv[] ) 
{
    Customer *thisCustomer = new Customer( "John Smith" );
    Movie *movie1 = new Movie( "The Departed", Movie::REGULAR );
    Rental *rental = new Rental( movie1, 4 ); 
    thisCustomer->addRental( rental );

    Movie *movie2 = new Movie( "The Imitation Game", Movie::NEW_RELEASE );
    thisCustomer->addRental( new Rental( movie2, 2 ) );
    cout <<  thisCustomer->statement() << endl;
    return 0;
}
