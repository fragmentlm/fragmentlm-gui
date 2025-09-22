# FragmentLM GUI Client

# Implementation
The client communicates with P2P network via proxy distributer service (DS).
Communication with DS is handled by TCP protocol on port 50001 in JSON objects.

## Client request
```json
{
    "startPos": 0,
    "fragment": "TOKENIZED TEXT FRAGMENT",
    "tokensTable": {},
    "tokensChecksum": "bytes"
}
```
- `startPos`: index of the first symbol of the fragment.
- `fragment`: tokenized fragment of original text, always in UTF8
- `tokensTable`: table of tokens that is to be used by nodes
- `tokensChecksum`: checksum of the token table, is used to fetch tokens from
within DS if none was provided in the request.

## DS immediate response
Network immediately returns response JSON:
```json
{
    "requestID": 12345678,
    "status": 0
}
```
- `requestID`: identifier of the operation assigned by DS. The operation should be considered alive
until a non-zero `status` is received.
- `status`: see [this section](##Operation status)

## DS final response
And when the work is done the network send the following packet:
```json
{
    "requestID": 12345678,
    "status": 0,
    "result": "TOKENS PROCESSED"
}
```
- `requestID`: identifier of the operation assigned by DS. The operation is dead once this
reply is given.
- `status`: see [[##Operation status]]
- `result`: processed tokenized fragment of the text, if present


## Operation status
Status value can be one the following:
- `0`: no error
- `1`: DS error, no connection
- `2`: DS error, no available nodes
- `3`: DS error, no available tokens
- `4`: DS error, operation rejected
- `5`: Network error, operation is lost
