#ifndef _LOADIMAGEMODULE_
#define _LOADIMAGEMODULE_

#include "../framework/ModuleInterface.hpp"
#include "../framework/ModuleBase.hpp"
#include <QObject>
#include <QtPlugin>

namespace uipf{


class LoadImageModule :  public QObject, ModuleBase
{
Q_OBJECT
Q_PLUGIN_METADATA(IID "org.tu-berlin.uipf.ModuleInterface" )
Q_INTERFACES(uipf::ModuleInterface)

	public:
		// constructor tells ModuleBase our name so we don't need to implement name()
		LoadImageModule(void): ModuleBase("loadImage"){};

		// destructor needs to be virtual otherwise it not called due polymorphism
		virtual ~LoadImageModule(void){};

		// runs the module chain with the params
		void run( std::map<std::string, uipf::Data::ptr& >& input,
			  std::map<std::string, std::string>& params,
		   	  std::map<std::string, uipf::Data::ptr >& output ) const Q_DECL_OVERRIDE;

		uipf::MetaData getMetaData() const Q_DECL_OVERRIDE;

};

}

#endif //LOADIMAGEMODULE
