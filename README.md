# CMPS-460
 <h1>Polyphase Sort/Merge</h1>
  <p>Data is moved from the large file into two (min 3 when using PFD) external drives</p>
 
 <h2>Perfect Fibonacci Distribution PFD</h2>
  <p>Finding the PFD</p>
  <p>The following Fibonacci numbers of order 3 are found by adding the 3 previous numbers together.</p>
  <table>
  <tr>
  <td>F1</td><td>T1</td><td>T2</td><td>T3</td>
  </tr>
  <tr>
  <td>1</td><td>1</td><td>0</td><td>0</td>
  </tr>
  <tr>
  <td>3</td><td>1</td><td>1</td><td>1</td>
  </tr>
  <tr>
  <td>5</td><td>2</td><td>2</td><td>1</td>
  </tr>
  <tr>
  <td>9</td><td>4</td><td>3</td><td>2</td>
  </tr>
  </table>
  <p>An alternative method for finding the next row of numbers is:</p>
  <table>
  <tr>
  <td>F1</td><td>T1</td><td>T2</td><td>T3</td>
  </tr>
  <tr>
  <td>9</td><td>4</td><td>3</td><td>2</td>
  </tr>
  <tr>
  <td></td><td>a<sub>n</sub></td><td>b<sub>n</sub></td><td>c<sub>n</sub></td>
  </tr>
  <tr>
  <td></td><td>a<sub>n</sub>+b<sub>n</sub></td><td>b<sub>n</sub>+c<sub>n</sub></td><td>a<sub>n</sub></td>
  </tr>
  <tr>
  <td>17</td><td>7</td><td>6</td><td>4</td>
  </tr>
  </table>
  <h3>Minimize the number of phases!</h3>
  <h2>When the number of records does not equal one of the Fibonacci numbers</h2>
  <p>If the number of records wo be sorted is 12 and the PFD order is 3, the 
  Fibonacci number 17 must be used.</p>
  <h1>Adding dummy records</h1>
  <p>Dummy records can be added to the beginning of the file or the end.</p>
  
  Example Run:
  
  PDF Menu

Enter the file size: 10001

PFD of order: 7

|  Sort #|      F1|      T1|      T2|      T3|      T4|      T5|      T6|      T7|
|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|:------:|
|        |   10001  |  --    |  --    |  --    |  --    |  --    |  --    |  --    |
|    1   |    --    |  2000  |  1984  |  1952  |  1888|     1761|     1508  |   1004|
|    2   |    1004  | 996    | 980    | 948    | 884   |   757   |   504  |    --|
|    3   |    500   | 492    | 476    | 444    | 380     | 253    |  --     |  504|
|    4   |    247   | 239    | 223    | 191    | 127|      --|       253   |   251|
|    5   |    120   | 112    | 96     | 64     | --   |    127 |     126 |     124|
|    6   |    56    | 48     | 32     | --     | 64     |  63    |   62|       60|
|    7   |    24    | 16     | --     | 32     | 32|       31      | 30     |  28|
|    8   |    8     | --     | 16     | 16     | 16  |     15|      14   |    12|
|    9   |    --    | 8      | 8      | 8      | 8     |   7  |      6  |      4|
|    10  |    4     | 4      | 4      | 4      | 4       | 3    |    2      |  --|
|    11  |    2     | 2      | 2      | 2      | 2     |   1      |  --   |    2|
|    12  |    1     | 1      | 1      | 1      | 1   |     --|       1    |   1|
|    13  |    --    | --     | --     | --     | --|       1   |     --  |    --|
