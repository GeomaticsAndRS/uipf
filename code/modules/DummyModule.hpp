#ifndef _DUMMYMODULE_
#define _DUMMYMODULE_

#include "../framework/ModuleInterface.hpp"
#include <QObject>
#include <QtPlugin>

namespace uipf{


class DummyModule :  public QObject, ModuleInterface
{
Q_OBJECT
Q_PLUGIN_METADATA(IID "org.tu-berlin.uipf.ModuleInterface" )
Q_INTERFACES(uipf::ModuleInterface)

	public:
		// constructor
		DummyModule(void){};
		// destructor
		~DummyModule(void){};

		// runs the module chain with the params
		void run( std::map<std::string, uipf::Data*>& input, 
			  std::map<std::string, std::string> params, 
		   	  std::map<std::string, uipf::Data*>& output, 
			  uipf::Context context ) const Q_DECL_OVERRIDE;

		std::string name() const Q_DECL_OVERRIDE;
};

}

#endif //DUMMYMODULE
