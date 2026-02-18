class IntArray
{
	public:
		int array[10];

		void fill(int value)
		{
			for (int i = 0; i < 10; i++)
				array[i] = value;
		}

		int& at(int index)
		{
			return array[index];
		}
};

template <typename T, int length>
class SampleArray
{
	public:
		T array[length];

		void fill(T value)
		{
			for (int i = 0; i < length; i++)
				array[i] = value;
		}

		T& at(T index)
		{
			return array[index];
		}
};

/* Array<int, 10> intArr; */

