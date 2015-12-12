# CMPS-460
<html>
<head> <title>Polyphase Sort/Merge using Perfect Fibonacci Distribution</title></head>
<body>
 
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
  Fibonacci number 17 must be used.
  <h1>Adding dummy records</h1>
  <p>Dummy records can be added to the beginning of the file or the end.</p>
<p>Enter the number of items to sort:</p>

 
<p>Enter the PFD #:</p>
</body>
</html>
