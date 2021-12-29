#include <cppunit/extensions/TAPListener.h>

#include "CoreSuite.h"
#include "TAPListenerTest.h"

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( TAPListenerTest,
                                       coreSuiteName() );

TAPListenerTest::TAPListenerTest()
{
}

TAPListenerTest::~TAPListenerTest()
{
}

void
TAPListenerTest::setUp()
{
}

void
TAPListenerTest::tearDown()
{
}

void
TAPListenerTest::testSuccess()
{
	CPPUNIT_NS::TAPListener listener(CPPUNIT_NS::stdCOut());

	//listener.startTestRun(NULL, NULL);
	//listener.startSuite(NULL);
	//listener.startTest(NULL);
	////listener.addFailure(TestFailure());
	//listener.endTest(NULL);
	//listener.endSuite(NULL);
	//listener.endTestRun(NULL, NULL);
}
