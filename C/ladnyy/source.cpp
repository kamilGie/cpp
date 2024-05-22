//kamil gieras
void Add(int val, int out[])
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
  for (int i = 0; i < size; i++) in[i]=0;
  in[0]=-1;
  for (int i = 0; i < size; i++) Add(in[i], out); 
}

void Union(int set[], int setB[], int *out) 
{
  out[0]=-1;
  for (int i = 0; set[i] != -1; i++) Add(set[i], out);
  for (int i = 0; setB[i] != -1; i++) Add(setB[i], out);
}

void Intersection(int set[], int setB[], int *out) 
{
  for (int i = 0; set[i] != -1; i++) for (int j = 0; setB[j] != -1; j++) if (set[i] == setB[j]) Add(set[i], out);
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


bool Element(int el, int set[])
{
  for (int i = 0; set[i] != -1; i++)
    if (set[i] == el)  return 1;

  return 0;
}


void Cardinality(int set[], int *size)
{
  *size = 0;
  while (set[*size] != -1) (*size)++;
}
