#ifndef TAPLISTENERTEST_H
#define TAPLISTENERTEST_H

#include <cppunit/extensions/HelperMacros.h>

class TAPListenerTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( TAPListenerTest );
  CPPUNIT_TEST( testSuccess );
  CPPUNIT_TEST_SUITE_END();

public:
  TAPListenerTest();
  virtual ~TAPListenerTest();

  virtual void setUp();
  virtual void tearDown();

  void testSuccess();

private:
  TAPListenerTest( const TAPListenerTest &copy );
  void operator =( const TAPListenerTest &copy );

};



#endif  // TESTRESULTTEST_H

