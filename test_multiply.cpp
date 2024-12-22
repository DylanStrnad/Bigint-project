/**
* Dylan Strnad
* BIGINT
* CS 23001
*/


// bigint Test Program
//
// Tests:  multiply, uses ==
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(1);
        bigint right(0);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 1);
        assert(right  == 0);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(1);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == 0);
        assert(right  == 1);
        assert(result == 0);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(123);
        bigint right(56);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==  123);
        assert(right  ==   56);
        assert(result == 6888);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(65);
        bigint right(321);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==    65);
        assert(right  ==   321);
        assert(result == 20865);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(9999);
        bigint right(2);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==  9999);
        assert(right  ==     2);
        assert(result == 19998);
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(2);
        bigint right(999999);
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   ==       2);
        assert(right  ==  999999);
        assert(result == 1999998);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(99);
        bigint right(99);
        bigint result;

        // Test
        result = left * right;

        // Verify
        assert(left   ==  99);
        assert(right  ==  99);
        assert(result ==  9801);
    }

     { 
        //------------------------------------------------------
        // Setup fixture
        bigint left("2098072077968903666432292814671497959132911206855947218521250206123381996325850750616919179324838845");
        bigint right("3080888100729931134661926052975793103713012836261344920707711450947982787863035171902458872925127730");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "2098072077968903666432292814671497959132911206855947218521250206123381996325850750616919179324838845");
        assert(right  == "3080888100729931134661926052975793103713012836261344920707711450947982787863035171902458872925127730");
        assert(result == "6463925299488115608431967227841281547364830075640555603629233290104243286893656751008240083235386532831574932707696339415537802722532521812728188223733076442831855056653804067703820602733933290671850");
    }

     { 
        //------------------------------------------------------
        // Setup fixture
        bigint left("3080888100729931134661926052975793103713012836261344920707711450947982787863035171902458872925127730");
        bigint right("2098072077968903666432292814671497959132911206855947218521250206123381996325850750616919179324838845");
        bigint result;
        
        // Test "
        result = left * right;
        
        // Verify
        assert(left   == "3080888100729931134661926052975793103713012836261344920707711450947982787863035171902458872925127730");
        assert(right  == "2098072077968903666432292814671497959132911206855947218521250206123381996325850750616919179324838845");
        assert(result == "6463925299488115608431967227841281547364830075640555603629233290104243286893656751008240083235386532831574932707696339415537802722532521812728188223733076442831855056653804067703820602733933290671850");
    }

     {
        //------------------------------------------------------
        // Setup fixture
        bigint left("59359");
        bigint right("6094867024893221776129268452449914700862495327201910137455519448726120996896056352545579230499632384");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "59359");
        assert(right  == "6094867024893221776129268452449914700862495327201910137455519448726120996896056352545579230499632384");
        assert(result == "361785211730636751409257246068974486728496860127378183849222178956933816254753009030753037543227678681856");
    }




    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("2222");
        bigint right("888888888888888888888888888888888888");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "2222");
        assert(right  == "888888888888888888888888888888888888");
        assert(result == "1975111111111111111111111111111111109136");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("777777777777777777777777777777777777777777777");
        bigint right("333333");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "777777777777777777777777777777777777777777777");
        assert(right  == "333333");
        assert(result == "259258999999999999999999999999999999999999999740741");
    }
    
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left("111111111111111111111111111111111111111111");
        bigint right("999999999999999999999999999999999999999999");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "111111111111111111111111111111111111111111");
        assert(right  == "999999999999999999999999999999999999999999");
        assert(result == "111111111111111111111111111111111111111110888888888888888888888888888888888888888889");
    }

     {
        //------------------------------------------------------
        // Setup fixture
        bigint left("67084336802853799445499192109440710259859684420014");
        bigint right("16076355338119715594474996521418381586001039465336");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "67084336802853799445499192109440710259859684420014");
        assert(right  == "16076355338119715594474996521418381586001039465336");
        assert(result == "1078471636064779573609546907262084117826158131534352476187794859908880888013061291156382503817634704");
    }

     {
        //------------------------------------------------------
        // Setup fixture
        bigint left("934839400538380015030812317722");
        bigint right("43671");
        bigint result;
        
        // Test 
        result = left * right;
        
        // Verify
        assert(left   == "934839400538380015030812317722");
        assert(right  == "43671");
        assert(result == "40825371460911593636410604727237462");
    }

    

    std::cout << "Done testing multiply" << std::endl;
    return 0;
}
