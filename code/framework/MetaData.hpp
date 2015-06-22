#ifndef METADATA_H
#define METADATA_H

#include <string>
#include <map>
#include "types/Data.hpp"

namespace uipf {

//Base class for all Descriptions
class Description
{
public:

	// constructor
	Description(std::string d, bool bOptional=false) : description_(d),bIsOptional_(bOptional) {};
	// constuctor to allow copying
	Description() {};
	// destructor
	virtual ~Description(void){};

	std::string getDescription() const { return description_; };
	bool getIsOptional() const { return bIsOptional_; };

protected:
	// a textual description
	std::string description_;
	bool bIsOptional_;
};

// holds meta data for input and output
class DataDescription : public Description {
	public:

		// constructor
		DataDescription(Type t, std::string d, bool bOptional=false) : Description (d,bOptional), type_(t) {};
		// constuctor to allow copying
		DataDescription() {};
		// destructor
		virtual ~DataDescription(void){};

		Type getType() { return type_; };

	private:
		// the type of the input/output data
		Type type_;

};

// holds meta data for module parameters
class ParamDescription : public Description {
	public:

		// constructor
		ParamDescription(std::string d, bool bOptional=false) : Description (d,bOptional) {};
		// constuctor to allow copying
		ParamDescription() {};
		// destructor
		virtual ~ParamDescription(void){};

};

// describes the module meta data
class MetaData : public Description {
	public:
		// constructor
		MetaData(
			std::string, // description
			std::map<std::string, DataDescription>, // input
			std::map<std::string, DataDescription>, // output
			std::map<std::string, ParamDescription> // params
		);
		// constuctor to allow copying
		MetaData(){};
		// destructor
		virtual ~MetaData(void){};

		// list of inputs  name => description details
		std::map<std::string, DataDescription> getInputs();

		// list of outputs  name => description details
		std::map<std::string, DataDescription> getOutputs();

		// list of parameters  name => description details
		std::map<std::string, ParamDescription> getParams();

		// get input by name
		DataDescription getInput(const std::string& ) const;
		// get output by name
		DataDescription getOutput(const std::string& ) const;
		// get param by name
		ParamDescription getParam(const std::string& ) const;


	private:


		std::map<std::string, DataDescription> inputs_;
		std::map<std::string, DataDescription> outputs_;
		std::map<std::string, ParamDescription> params_;

};

}

#endif

