# Decision logic test cases

| Person detected | Light ON | AC ON | Expected alert |
|---|---|---|---|
| true | true | true | false |
| true | true | false | false |
| true | false | true | false |
| true | false | false | false |
| false | true | false | true |
| false | false | true | true |
| false | true | true | true |
| false | false | false | false |

Also test:
- no alert on a single transient frame;
- alert after the chosen confirmation rule;
- no repeated alert during cooldown;
- retry behavior if Wi-Fi/API is unavailable.
