#ifndef CPPUNIT_TAPLISTENER_H
#define CPPUNIT_TAPLISTENER_H

#include <cppunit/portability/Stream.h>
#include <cppunit/TestListener.h>


CPPUNIT_NS_BEGIN


/*!
 * \brief TestListener that show the status of each TestCase test result.
 * \ingroup TrackingTestExecution
 */
class CPPUNIT_API TAPListener : public TestListener
{
private:
  OStream &m_stream;
  bool m_lastTestFailed;
  uint32_t m_counter;

public:
  /*! Constructs a TextTestProgressListener object.
   */
  TAPListener(OStream &stream);

  /// Destructor.
  virtual ~TAPListener() override;

public:
  /// Called when just before a TestCase is run.
  virtual void startTest( Test * /*test*/ ) override;

  /*! \brief Called when a failure occurs while running a test.
   * \see TestFailure.
   * \warning \a failure is a temporary object that is destroyed after the
   *          method call. Use TestFailure::clone() to create a duplicate.
   */
  virtual void addFailure( const TestFailure & /*failure*/ ) override;

  /// Called just after a TestCase was run (even if a failure occured).
  virtual void endTest( Test * /*test*/ ) override;

  /*! \brief Called by a TestComposite just before running its child tests.
   */
  virtual void startSuite( Test * /*suite*/ ) override;

  /*! \brief Called by a TestComposite after running its child tests.
   */
  virtual void endSuite( Test * /*suite*/ ) override;

  /*! \brief Called by a TestRunner before running the test.
   *
   * You can use this to do some global initialisation. A listener
   * could also use to output a 'prolog' to the test run.
   *
   * \param test Test that is going to be run.
   * \param eventManager Event manager used for the test run.
   */
  virtual void startTestRun( Test *test,
                             TestResult *eventManager ) override;

  /*! \brief Called by a TestRunner after running the test.
   *
   * TextTestProgressListener use this to emit a line break. You can also use this
   * to do some global uninitialisation.
   *
   * \param test Test that was run.
   * \param eventManager Event manager used for the test run.
   */
  virtual void endTestRun( Test * test,
                           TestResult *eventManager ) override;
};


CPPUNIT_NS_END

#endif // CPPUNIT_TAPLISTENER_H
