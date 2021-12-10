#ifndef __NICE_NMAP____
#define __NICE_NMAP____
#include <map>
#include <string>
#include "smart_ref.hpp"
#include "Type.h"
#include <type_traits>

namespace nicehero{
	template <typename K, typename V>
	using basemap = std::map<K, V>;

	template <class K,class V, template<typename,typename> class BaseMap = basemap >
	class nmap : public BaseMap<K,V> 
	{
	public:
		
		smart_ref<V> get(const K& k, const V& rDefault) {
			auto it = BaseMap<K,V> ::find(k);
			if (it == BaseMap<K,V> ::end()) {
				return rDefault;
			}
			return smart_ref<V>(&it->second);
		}
		const_smart_ref<V> get(const K& k, const V& rDefault) const {
			auto it = BaseMap<K,V> ::find(k);
			if (it == BaseMap<K,V> ::end()) {
				return rDefault;
			}
			return const_smart_ref<V>(&it->second);
		}
		const V* get(const K& k) const{
			auto it = BaseMap<K,V> ::find(k);
			if (it == BaseMap<K,V> ::end()) {
				return nullptr;
			}
			return &it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, std::string, BaseMap> 
		: public BaseMap<K, std::string>
	{
	public:
		const char* get(const K& k, const char* rDefault = "") const {
			auto it = BaseMap<K, std::string>::find(k);
			if (it == BaseMap<K, std::string>::end()) {
				return rDefault;
			}
			return it->second.c_str();
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, const char*, BaseMap> 
		: public BaseMap<K, const char*> 
	{
	public:
		const char* get(const K& k, const char* rDefault = "") const {
			auto it = BaseMap<K, std::string>::find(k);
			if (it == BaseMap<K, std::string>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, bool, BaseMap> 
		: public BaseMap<K,bool> 
	{
		using V = bool;
	public:
		V get(const K& k, V rDefault = false) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};

	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, ui8, BaseMap> 
		: public BaseMap<K,ui8> 
	{
		using V = ui8;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, ui16, BaseMap> 
		: public BaseMap<K,ui16> 
	{
		using V = ui16;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, ui32, BaseMap> 
		: public BaseMap<K,ui32> 
	{
		using V = ui32;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, ui64, BaseMap> 
		: public BaseMap<K,ui64> 
	{
		using V = ui64;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, i16, BaseMap> 
		: public BaseMap<K,i16> 
	{
		using V = i16;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, i32, BaseMap> 
		: public BaseMap<K,i32> 
	{
		using V = i32;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
	template <class K, template<typename, typename> class BaseMap>
	class nmap<K, i64, BaseMap> 
		: public BaseMap<K,i64> 
	{
		using V = i64;
	public:
		V get(const K& k, V rDefault = 0) const {
			auto it = BaseMap<K, V>::find(k);
			if (it == BaseMap<K, V>::end()) {
				return rDefault;
			}
			return it->second;
		}
	};
	
}
#endif
