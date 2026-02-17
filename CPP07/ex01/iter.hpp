
template <typename T1, typename T2, typename T3>
void	iter(*T arr[], const T2 value, T3 f)
{
	for (i = 0; i < value; i++)
	{
		f(*arr[i]);
	}
};
