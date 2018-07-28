// Primitive DOM Selector
//
var dom = null;

/*
 * select item
 */
// all return a HTMLElement
dom = document.getElementById('id-name');
dom = document.querySelector('#id-name');

/*
 * select items
 */
// return HTMLCollection
dom = document.getElementsByClassName('class-name');
dom = document.getElementsByTagName('div');
dom = document.getElementsByTagNameNS('http://www.w3.org/1999/xhtml', 'div');

// return NodeList
dom = document.querySelectorAll('.class-name');
dom = document.getElementsByName('name-attr');

// console.log(dom, dom.constructor);
