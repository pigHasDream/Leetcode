class SingletonCL {
	public:
		static SingletonCL& getInstance() {
      // Guaranteed to be destroyed.
			static SingletonCL instance_; 
			// Instantiated on first use.
			return instance_;
		}

	private:
		SingletonCL() {
      // ... do something
    }  

	public:
		Singleton(const Singleton&) = delete;
		void operator=(const Singleton&)  = delete;

		// Note: Scott Meyers mentions in his Effective Modern
		//       C++ book, that deleted functions should generally
		//       be public as it results in better error messages
		//       due to the compilers behavior to check accessibility
		//       before deleted status
};
