#include <cppunit/extensions/TAPListener.h>

#include <cppunit/Test.h>

CPPUNIT_NS_BEGIN

TAPListener::TAPListener(OStream &stream)
	:m_stream(stream),
	m_lastTestFailed(false),
	m_counter(0)
{
}

TAPListener::~TAPListener()
{
}

void TAPListener::startTest( Test * /*test*/ )
{
	m_lastTestFailed = false;
}

void TAPListener::addFailure( const TestFailure & /*failure*/ )
{
	m_lastTestFailed = true;
}

void TAPListener::endTest( Test *test )
{
	m_stream << (!m_lastTestFailed ? "ok " : "not ok ") << ++m_counter << " " << test->getName() << std::endl;
}

void TAPListener::startSuite( Test *suite )
{
	m_stream << "# " << suite->getName() << ": " << suite->countTestCases() << " cases" << std::endl;
}

void TAPListener::endSuite( Test * /*suite*/ )
{
	//m_stream << "# Testing " << suite->getName() << " done."<< std::endl;
}

void TAPListener::startTestRun( Test *test,
                   TestResult * /*eventManager*/ )
{
	m_stream << "1.." << test->countTestCases() << std::endl;
}

void TAPListener::endTestRun( Test * /*test*/,
                           TestResult * /*eventManager*/ )
{
}

CPPUNIT_NS_END
