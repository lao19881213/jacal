/// @file MajorCycle.h

/// @brief Load a CASA Measurement Set in the DaliugeApplication Framework
/// @details We will build on the LoadParset structure - but use the contents
/// of the parset to load a measurement set.



#ifndef ASKAP_FACTORY_MAJORCYCLE_H
#define ASKAP_FACTORY_MAJORCYCLE_H

#include <daliuge/DaliugeApplication.h>

#include <casacore/casa/Quanta/MVDirection.h>

#include <boost/shared_ptr.hpp>

// LOFAR ParameterSet
#include <Common/ParameterSet.h>
// ASKAPSoft data accessor
#include <dataaccess/TableDataSource.h>

#include <fitting/Params.h>



namespace askap {
  /// @brief Loads visibility set
  /// @details Loads a configuration from a file drop and a visibility set from a CASA::Measurement Set
    class MajorCycle : public DaliugeApplication

    {

    public:

        typedef boost::shared_ptr<MajorCycle> ShPtr;

        MajorCycle(dlg_app_info *raw_app);

        static inline std::string ApplicationName() { return "MajorCycle";}

        virtual ~MajorCycle();

        static DaliugeApplication::ShPtr createDaliugeApplication(dlg_app_info *raw_app);

        virtual int init(const char ***arguments);

        virtual int run();

        virtual void data_written(const char *uid, const char *data, size_t n);

        virtual void drop_completed(const char *uid, drop_status status);

        


        private:

            /// The model
            askap::scimath::Params::ShPtr itsModel;

            // Parameter set
            LOFAR::ParameterSet itsParset;

            // Its channel of data

            casa::IPosition freqInterval;


            casa::IPosition timeInterval;

            // Its tangent point
            std::vector<casa::MVDirection> itsTangent;

            int itsChan;


            // utility to build an Imaging Normal Equation from a parset
            // void buildNE();

            // these are the steps required by buildNE




    };

} // namespace askap


#endif //