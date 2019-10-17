'use strict';(function(d){function O(a){return function(b){return a.apply(b,la.call(arguments,1))}}function U(){var a,b,g=new ma(function(g,e){a=g;b=e});g[E]=a;g[Q]=b;return g}function V(a){try{F(a,e,function(){})}catch(b){}}function q(){this.back=this.front={elements:new ca,next:e};this.size=this.cursor=0}function v(a,b,g){a=a===e?{}:a;var c=b===e?{}:b;b=c.size;c=c.highWaterMark;c===e&&(c=1);this[p]=0;this[p]=this[p]&-7|0;this[u]=e;this[K]=e;this[y]=e;var d=a.type;if("bytes"===String(d))throw new G("bytes type is not yet implemented");
if(d!==e)throw new G("Invalid type is specified");this[y]=new L(this,a,b,c,g)}function L(a,b,g,d){if(!1===B(a))throw new c("Illegal constructor");if(a[y]!==e)throw new c("Illegal constructor");this[l]=a;this[W]=b;this[z]=new q;this[H]=0;this[h]=0;g=na(g,d);this[da]=g.size;this[ea]=g.highWaterMark;var P=this;b=oa(b,"start",this,"underlyingSource.start");F(C(b),function(){P[h]|=1;M(P)},function(b){0===k(a)&&A(P,b)})}function pa(a,b){a[z]=new q;return fa(a[W],"cancel",b,"underlyingSource.cancel")}function N(a){if(!1===
B(a))throw new c("ReadableStreamReader constructor argument is not a readable stream");if(!0===I(a))throw new c("ReadableStreamReader constructor can only accept readable streams that are not yet locked to a reader");this[x]=a;a[u]=this;switch(k(a)){case 0:this[t]=U();break;case 1:this[t]=C(e);break;case 2:this[t]=n(a[K]),V(this[t])}this[r]=new q}function X(a){return new N(a)}function R(a,b){a[p]|=1;var g=k(a);if(1===g)return C(e);if(2===g)return n(a[K]);Y(a);a=pa(a[y],b);return F(a,function(){return e})}
function S(a){var b=a[l];a[h]|=2;0===a[z].length&&Y(b)}function T(a,b){var g=a[l];if(!0===I(g)&&0<g[u][r].length)g[u][r].shift()[E]({value:b,done:!1});else{var c=1,d=a[da];if(d!==e)try{c=d(b)}catch(w){throw 0===k(g)&&A(a,w),w;}try{c=Z(c);if(ha(c)||c===+qa||0>c)throw new G("The return value of a queuing strategy's size function must be a finite, non-NaN, non-negative number");a[H]+=c;a[z].push({value:b,size:c})}catch(w){throw 0===k(g)&&A(a,w),w;}}M(a)}function k(a){return(a[p]&6)>>1}function A(a,b){a[z]=
new q;ra(a[l],b)}function ra(a,b){a[K]=b;a[p]=a[p]&-7|4;a=a[u];if(a===e)return e;!0===D(a)&&(a[r].forEach(function(a){a[Q](b)}),a[r]=new q);a[t][Q](b);V(a[t])}function Y(a){a[p]=a[p]&-7|2;a=a[u];if(a===e)return e;!0===D(a)&&(a[r].forEach(function(a){a[E]({value:e,done:!0})}),a[r]=new q);a[t][E](e)}function aa(a){var b=k(a[l]);return 1===b?0:2===b?null:a[ea]-a[H]}function B(a){return J(a,y)}function I(a){return a[u]!==e}function D(a){return J(a,r)}function ba(a){a=a[x];a[p]|=1;if(1===k(a))return C({value:e,
done:!0});if(2===k(a))return n(a[K]);a=a[y];var b=a[l];if(0<a[z].length){var c=a[z].shift();a[H]-=c.size;c=c.value;a[h]&2&&0===a[z].length?Y(b):M(a);a=C({value:c,done:!1})}else c=U(),b[u][r].push(c),M(a),a=c;return a}function M(a){if(!1===sa(a))return e;if(a[h]&4)return a[h]|=8,e;a[h]|=4;var b=fa(a[W],"pull",a,"underlyingSource.pull");F(b,function(){a[h]&=-5;a[h]&8&&(a[h]&=-9,M(a))},function(b){0===k(a[l])&&A(a,b)})}function sa(a){var b=a[l],c=k(b);return 1===c||2===c||a[h]&2||!(a[h]&1)?!1:!0===I(b)&&
0<b[u][r].length||0<aa(a)?!0:!1}function ia(a){function b(){return F(ba(c),function(a){var b=a.value;!0===a.done&&!1===d&&(!1===f&&S(q),!1===h&&S(r),d=!0);!0!==d&&(!1===f&&T(q,b),!1===h&&T(r,b))})}var c=X(a),d=!1,f=!1,h=!1,k,m,l=U(),n=new v({pull:b,cancel:function(b){f=!0;k=b;!0===h&&(b=R(a,[k,m]),l[E](b));return l}}),p=new v({pull:b,cancel:function(b){h=!0;m=b;!0===f&&(b=R(a,[k,m]),l[E](b));return l}}),q=n[y],r=p[y];F(c[t],e,function(a){!0!==d&&(A(q,a),A(r,a),d=!0)});return[n,p]}function na(a,b){if(a!==
e&&"function"!==typeof a)throw new c("A queuing strategy's size property must be a function");b=Z(b);if(ha(b))throw new G("A queueing strategy's highWaterMark property must be a nonnegative, non-NaN number");if(0>b)throw new G("A queueing strategy's highWaterMark property must be a nonnegative, non-NaN number");return{size:a,highWaterMark:b}}function oa(a,b,d,f){b=a[b];if(b===e)return e;if("function"!==typeof b)throw new c(ja(f));return ka(b,a,d)}function fa(a,b,d,f){try{var g=a[b]}catch(w){return n(w)}if(g===
e)return C(e);if("function"!==typeof g)return n(new c(ja(f)));try{return C(ka(g,a,d))}catch(w){return n(w)}}var m=d.Object.defineProperty,ca=d.Array,f=d.Symbol,la=d.Array.prototype.slice,ma=d.Promise,E=f("[[Resolve]]"),Q=f("[[Reject]]");m(q.prototype,"length",{get:function(){return this.size}});q.prototype.push=function(a){++this.size;if(16384===this.back.elements.length){var b=this.back;this.back={elements:new ca,next:e};b.next=this.back}this.back.elements.push(a)};q.prototype.shift=function(){--this.size;
this.front.elements.length===this.cursor&&(this.front=this.front.next,this.cursor=0);var a=this.front.elements[this.cursor];this.front.elements[this.cursor]=e;++this.cursor;return a};q.prototype.forEach=function(a){for(var b=this.cursor,c=this.front,d=c.elements;b!==d.length||c.next!==e;)b===d.length&&(c=c.next,d=c.elements,b=0),a(d[b]),++b};q.prototype.peek=function(){return this.front.elements.length===this.cursor?this.front.next.elements[0]:this.front.elements[this.cursor]};var u=f("[[reader]]"),
K=f("[[storedError]]"),y=f("[[controller]]"),t=f("[[closedPromise]]"),x=f("[[ownerReadableStream]]"),r=f("[[readRequests]]"),p=f("bit field for [[state]] and [[disturbed]]"),W=f("[[underlyingSource]]"),l=f("[[controlledReadableStream]]"),z=f("[[queue]]"),H=f("[[totalQueuedSize]]"),da=f("[[strategySize]]"),ea=f("[[strategyHWM]]"),h=f("bit field for [[started]], [[closeRequested]], [[pulling]], [[pullAgain]]"),e=d.undefined,qa=d.Infinity,J=O(d.Object.hasOwnProperty),ka=O(d.Function.prototype.call);
O(d.Function.prototype.apply);var c=d.TypeError,G=d.RangeError,Z=d.Number,ha=Z.isNaN;f=d.Promise;var F=O(f.prototype.then),C=f.resolve.bind(f),n=f.reject.bind(f),ja=function(a){return a+" must be a function or undefined"};m(v.prototype,"locked",{enumerable:!1,configurable:!0,get:function(){if(!1===B(this))throw new c("Illegal invocation");return I(this)}});m(v.prototype,"cancel",{enumerable:!1,configurable:!0,writable:!0,value:function(a){return!1===B(this)?n(new c("Illegal invocation")):!0===I(this)?
n(new c("Cannot cancel a readable stream that is locked to a reader")):R(this,a)}});m(v.prototype,"getReader",{enumerable:!1,configurable:!0,writable:!0,value:function(a){a=(a===e?{}:a).mode;if(!1===B(this))throw new c("Illegal invocation");if("byob"===a)throw new c("This readable stream does not support BYOB readers");if(a===e)return X(this);throw new G('Invalid reader mode given: expected undefined or "byob"');}});m(v.prototype,"pipeThrough",{enumerable:!1,configurable:!0,writable:!0,value:function(a,
b){throw new c("pipeThrough not implemented");}});m(v.prototype,"pipeTo",{enumerable:!1,configurable:!0,writable:!0,value:function(a){throw new c("pipeTo not implemented");}});m(v.prototype,"tee",{enumerable:!1,configurable:!0,writable:!0,value:function(){if(!1===B(this))throw new c("Illegal invocation");return ia(this)}});m(L.prototype,"desiredSize",{enumerable:!1,configurable:!0,get:function(){if(!1===J(this,l))throw new c("Illegal invocation");return aa(this)}});m(L.prototype,"close",{enumerable:!1,
configurable:!0,writable:!0,value:function(){if(!1===J(this,l))throw new c("Illegal invocation");var a=this[l];if(this[h]&2)throw new c("Cannot close a readable stream that has already been requested to be closed");a=k(a);if(2===a)throw new c("Cannot close an errored readable stream");if(1===a)throw new c("Cannot close a closed readable stream");return S(this)}});m(L.prototype,"enqueue",{enumerable:!1,configurable:!0,writable:!0,value:function(a){if(!1===J(this,l))throw new c("Illegal invocation");
var b=this[l];if(this[h]&2)throw new c("Cannot enqueue a chunk into a readable stream that is closed or has been requested to be closed");b=k(b);if(2===b)throw new c("Cannot enqueue a chunk into an errored readable stream");if(1===b)throw new c("Cannot enqueue a chunk into a closed readable stream");return T(this,a)}});m(L.prototype,"error",{enumerable:!1,configurable:!0,writable:!0,value:function(a){if(!1===J(this,l))throw new c("Illegal invocation");var b=k(this[l]);if(2===b)throw new c("Cannot error a readable stream that is already errored");
if(1===b)throw new c("Cannot error a close readable stream");return A(this,a)}});m(N.prototype,"closed",{enumerable:!1,configurable:!0,get:function(){return!1===D(this)?n(new c("Illegal invocation")):this[t]}});m(N.prototype,"cancel",{enumerable:!1,configurable:!0,writable:!0,value:function(a){return!1===D(this)?n(new c("Illegal invocation")):this[x]===e?n(new c("This readable stream reader has been released and cannot be used to cancel its previous owner stream")):R(this[x],a)}});m(N.prototype,"read",
{enumerable:!1,configurable:!0,writable:!0,value:function(){return!1===D(this)?n(new c("Illegal invocation")):this[x]===e?n(new c("This readable stream reader has been released and cannot be used to read from its previous owner stream")):ba(this)}});m(N.prototype,"releaseLock",{enumerable:!1,configurable:!0,writable:!0,value:function(){if(!1===D(this))throw new c("Illegal invocation");if(this[x]===e)return e;if(0<this[r].length)throw new c("Cannot release a readable stream reader when it still has outstanding read() calls that have not yet settled");
if(0===k(this[x])){var a=new c("This readable stream reader has been released and cannot be used to monitor the stream's state");this[t][Q](a)}else this[t]=n(new c("This readable stream reader has been released and cannot be used to monitor the stream's state"));V(this[t]);this[x][u]=e;this[x]=e}});m(d,"ReadableStream",{value:v,enumerable:!1,configurable:!0,writable:!0});d.AcquireReadableStreamDefaultReader=X;d.IsReadableStream=B;d.IsReadableStreamDisturbed=function(a){return a[p]&1};d.IsReadableStreamLocked=
I;d.IsReadableStreamReadable=function(a){return 0===k(a)};d.IsReadableStreamClosed=function(a){return 1===k(a)};d.IsReadableStreamErrored=function(a){return 2===k(a)};d.IsReadableStreamDefaultReader=D;d.ReadableStreamDefaultReaderRead=ba;d.ReadableStreamTee=ia;d.ReadableStreamDefaultControllerClose=S;d.ReadableStreamDefaultControllerGetDesiredSize=aa;d.ReadableStreamDefaultControllerEnqueue=T;d.ReadableStreamDefaultControllerError=A})(this);