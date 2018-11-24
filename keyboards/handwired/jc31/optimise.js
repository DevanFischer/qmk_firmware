const fs = require('fs')
const stream = fs.createWriteStream('possible.txt')

var permArr = [], usedChars = [];
function permute(input) {
	//convert input into a char array (one element for each character)
	var i, ch, chars = input.split("");
	for (i = 0; i < chars.length; i++) {
		//get and remove character at index "i" from char array
		ch = chars.splice(i, 1);
		//add removed character to the end of used characters
		usedChars.push(ch);
		//when there are no more characters left in char array to add, add used chars to list of permutations
		if (chars.length == 0) {
      //permArr[permArr.length] = usedChars.join("");
      const r = usedChars.join('')
      stream.write(r)
      stream.write('\n')
    }
		//send characters (minus the removed one from above) from char array to be permuted
		permute(chars.join(""));
		//add removed character back into char array in original position
		chars.splice(i, 0, ch);
		//remove the last character used off the end of used characters array
		usedChars.pop();
	}
}

const ds = new Date()
//const result = permute('etaoinsrhldcumf')
permute('etaoinsrhld')

const de = new Date()
console.log(de-ds)
