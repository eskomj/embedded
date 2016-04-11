#ifndef D_harjoitus8BuildTime_H
#define D_harjoitus8BuildTime_H

///////////////////////////////////////////////////////////////////////////////
//
//  harjoitus8BuildTime is responsible for recording and reporting when
//  this project library was built
//
///////////////////////////////////////////////////////////////////////////////

class harjoitus8BuildTime
  {
  public:
    explicit harjoitus8BuildTime();
    virtual ~harjoitus8BuildTime();
    
    const char* GetDateTime();

  private:
      
    const char* dateTime;

    harjoitus8BuildTime(const harjoitus8BuildTime&);
    harjoitus8BuildTime& operator=(const harjoitus8BuildTime&);

  };

#endif  // D_harjoitus8BuildTime_H
