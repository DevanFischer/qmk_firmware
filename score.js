const fs = require('fs')

const a = {
  name: 'Stagger',
  a: 0.0,
  b: 2.25,
  c: 1.0,
  d: 1.0,
  e: 0.0,
  f: 1.0,
  g: 1.0,
  h: 1.0,
  i: 0.0,
  j: 2.25,
  k: 1.0,
  l: 1.0,
  m: 1.75,
  n: 0.0,
  o: 0.0,
  p: 1.0,
  q: 1.0,
  r: 0.0,
  s: 0.0,
  t: 0.0,
  u: 1.0,
  v: 1.75,
  w: 1.0,
  x: 1.0,
  y: 1.0,
  z: 1.0,
}

const b = {
  name: 'Matrix',
  a: 0.0,
  b: 2.0,
  c: 1.0,
  d: 1.0,
  e: 0.0,
  f: 1.0,
  g: 1.0,
  h: 1.0,
  i: 0.0,
  j: 2.0,
  k: 1.0,
  l: 1.0,
  m: 2.0,
  n: 0.0,
  o: 0.0,
  p: 1.0,
  q: 1.0,
  r: 0.0,
  s: 0.0,
  t: 0.0,
  u: 1.0,
  v: 2.0,
  w: 1.0,
  x: 1.0,
  y: 1.0,
  z: 1.0,
}

const layouts = [a, b]
const scores = [0, 0]

//const text = 'Now is the time for all good, jolly men and boys to come to the aid of their country'
const text = fs.readFileSync('aiwl.txt').toString()
const letters = text.split('').filter(v => v >= 'a' && v <= 'z')

for (let i=0; i < letters.length; i++) {
  for (let j=0; j < layouts.length; j++) {
    scores[j] += layouts[j][letters[i]]
  }
}

for (let j=0; j < layouts.length; j++) {
  console.log(layouts[j].name, ' = ', scores[j] * 19 * 0.0393701 / 12)
}
