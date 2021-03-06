// See the file  in the main distribution directory for copyright.

#include "DNS.h"
#include "plugin/Plugin.h"
#include "analyzer/Component.h"

namespace plugin {
namespace Zeek_DNS {

class Plugin : public plugin::Plugin {
public:
	plugin::Configuration Configure() override
		{
		AddComponent(new ::analyzer::Component("DNS", ::analyzer::dns::DNS_Analyzer::Instantiate));
		AddComponent(new ::analyzer::Component("Contents_DNS", nullptr));

		plugin::Configuration config;
		config.name = "Zeek::DNS";
		config.description = "DNS analyzer";
		return config;
		}
} plugin;

}
}
