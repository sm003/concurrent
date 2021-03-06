#include "test_helper.hpp"
#include <random>

namespace test_helper {

   /** Random int function from http://www2.research.att.com/~bs/C++0xFAQ.html#std-random */
   int random_int(int low, int high) {
      using namespace std;
      static std::random_device rd; // Seed with a real random value, if available
      static default_random_engine engine{rd()};
      typedef uniform_int_distribution<int> Distribution;
      static Distribution distribution{};

      return distribution(engine, Distribution::param_type{low, high});
   }
   
   
   
   

   void DoAFlipAtomic(concurrent<FlipOnce>& flipper) {
      return flipper.call(&FlipOnce::doFlipAtomic).get();
   }

   void DoALambdaFlipAtomic(concurrent<FlipOnce>& flipper) {
      return flipper.lambda([] (FlipOnce& flip) { flip.doFlipAtomic(); }).get();
   }


}
