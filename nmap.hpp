#ifndef __NICE_NMAP____
#define __NICE_NMAP____
#include <map>
#include <string>
#include "smart_ref.hpp"
#include "Type.h"

namespace nicehero{
	template <class K,class V, template<typename,typename> class basemap = std::map >
	class nmap : public basemap<K,V> 
	{
	public:
		smart_ref<V> get(const K& k, const V& rDefault) {
			auto it = basemap<K,V> ::find(k);
			if (it == basemap<K,V> ::end()) {
				return rDefault;
			}
			return smart_ref<V>(&it->second);
		}
		const_smart_ref<V> get(const K& k, const V& rDefault) const {
			auto it = basemap<K,V> ::find(k);
			if (it == basemap<K,V> ::end()) {
				return rDefault;
			}
			return const_smart_ref<V>(&it->second);
		}
	};

	template <class K, template<typename, typename> class basemap>
	class nmap<K, std::string, basemap> 
		: public basemap<K, std::string>
	{
	public:
		const char* get(const K& k, const char* rDefault = "") const {
			auto it = basemap<K, std::string>::find(k);
			if (it == basemap<K, std::string>::end()) {
				return rDefault;
			}
			return it->second.c_str();
		}
	};

	template <class K, template<typename, typename> class basemap>
	class nmap<K, const char*, basemap> 
		: public basemap<K, const char*> 
	{
	public:
		const char* get(const K& k, const char* rDefault = "") const {
			auto it = basemap<K, std::string>::find(k);
			if (it == basemap<K, std::string>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, ui8, basemap> 
		: public basemap<K,ui8> 
	{
		using V = ui8;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, ui16, basemap> 
		: public basemap<K,ui16> 
	{
		using V = ui16;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, ui32, basemap> 
		: public basemap<K,ui32> 
	{
		using V = ui32;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, ui64, basemap> 
		: public basemap<K,ui64> 
	{
		using V = ui64;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, i16, basemap> 
		: public basemap<K,i16> 
	{
		using V = i16;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, i32, basemap> 
		: public basemap<K,i32> 
	{
		using V = i32;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class basemap>
	class nmap<K, i64, basemap> 
		: public basemap<K,i64> 
	{
		using V = i64;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = basemap<K, V>::find(k);
			if (it == basemap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
}
#endif
