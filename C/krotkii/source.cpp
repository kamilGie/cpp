//kamil gieras
void Add(int val, int *out)
{
  if (val<=0||val>4095)
    return;
  
  int i = 0;
  while (out[i] != -1 && out[i] != val) i++;

  if (out[i] == -1){
    out[i] = val;
    out[i + 1] = -1;
  }
}

void Create(int size, int in[], int *out)
{
  for (int i = 0; i < size; i++) Add(in[i], out); 
}

void Union(int set[], int setB[], int *out) 
{
  for (int i = 0; set[i] != -1; i++) Add(set[i], out);
  for (int i = 0; setB[i] != -1; i++) Add(setB[i], out);
}

void Intersection(int set[], int setB[], int *out) 
{
  for (int i = 0; set[i] != -1; i++) for (int j = 0; setB[j] != -1; j++) if (set[i] == setB[j]) Add(set[i], out);
}

void Difference(int set[], int setB[], int *out)
{
  for (int i = 0; set[i] != -1; i++) {
    bool wystapila = 0;
    for (int j = 0; setB[j] != -1; j++)if (set[i] == setB[j]) wystapila = 1;
    if (!wystapila) Add(set[i], out);
  }
}

void Symmetric(int set[], int setB[], int *out)
{
  Difference(set, setB, out);
  Difference(setB, set, out);
}

void Complement(int set[], int *out) 
{
  bool wystapila[4096] = {};
  for (int i = 0; set[i] != -1; i++) wystapila[set[i]] = 1;
  
  for (int i = 1; i < 4096; i++)
    if (!wystapila[i]) Add(i, out);
}

bool Subset(int podZbior[], int zbioru[])
{
  for (int i = 0; podZbior[i] != -1; i++) {
    bool jestToPozdbior = 0;
    for (int j = 0; zbioru[j] != -1; j++) if (podZbior[i] == zbioru[j]) jestToPozdbior = 1;
    if (!jestToPozdbior) return 0;
  }
  return 1;
}

bool Equal(int set[], int setB[])
{
  return Subset(set, setB) && Subset(setB, set);
}

bool Empty(int set[])
{
  return set[0] == -1;
}

bool Nonempty(int set[])
{
  return !Empty(set);
}

double Arithmetic(int set[])
{
  if (set[0] == -1) return 0;
  int size = 0;   double av = 0;
  for (; set[size] != -1; size++) av += set[size];
  return av / size;
}

double Harmonic(int set[])
{
  if (set[0] == -1) return 1;
  int size = 0; double av = 0;
  for (; set[size] != -1; size++) av += 1.0 / set[size];
  return (double)size / av;
}

bool Element(int el, int set[])
{
  for (int i = 0; set[i] != -1; i++)
    if (set[i] == el)  return 1;

  return 0;
}

void MinMax(int set[], int* min, int& max)
{
  if (set[0] == -1) return;

  *min = max = set[0];
  for (int i = 1; set[i] != -1; i++) {
    if (*min > set[i])  *min = set[i];
    if (max < set[i])  max = set[i];
  }
}

void Cardinality(int set[], int *size)
{
  *size = 0;
  while (set[*size] != -1) (*size)++;
}

void Properties(int set[], char Ch[], double &artmetic, double *harmonic, int & min, int *max, int& pow)
{
  for (int i = 0; Ch[i] != '\0'; i++) {
    if (Ch[i] == 'a' || Ch[i] == 'A') artmetic = Arithmetic(set);
    if (Ch[i] == 'h' || Ch[i] == 'H') *harmonic = Harmonic(set);
    if (Ch[i] == 'm' || Ch[i] == 'M') MinMax(set, &min, *max);
    if (Ch[i] == 'c' || Ch[i] == 'C') Cardinality(set, &pow);
  }
}